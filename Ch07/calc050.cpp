#include "std_lib_facilities.h"

constexpr char number = '8';		//token típusok
constexpr char quit = 'q';
constexpr char print = ';';
constexpr char name = 'a';
constexpr char let = 'L';
constexpr char square_root = '@';
constexpr char cpow = 'p';

const string declkey = "let";		//kulcsszavak
const string sqrtkey = "sqrt";
const string powkey = "cpow";

double expression();

class Variable {
public:
	string name;
	double value;
};

vector<Variable> var_table;

bool is_declared(string var){
	for (const auto& v : var_table)
		if (v.name == var) return true;
	return false;
}

double define_name (string var, double val){
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable{var,val});
	return val;
}

double get_value(string s){
	for(const auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined variable", s);
}

void set_value(string s, double d){
	for (auto& v : var_table)
		if(v.name == s){
			v.value = d;
			return;
		}
		error("set: undefined variable", s);
}

class Token{
public:
	char kind;		//érték és név ettől függően inicializálódik, token típus
	double value;
	string name;
	Token(): kind(0) {}
	Token(char ch): kind(ch), value(0) {}
	Token(char ch, double val): kind(ch), value(val) {}
	Token(char ch, string n): kind(ch), name(n) {}
};

class Token_stream {
public:
	Token_stream();		//cin-ből olvas
	Token get();
	void putback(Token t);		//token visszarakása
	void ignore(char c);
private:
	bool full;		//van-e token a pufferben?
	Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}		//nincs token a pufferben

void Token_stream::putback(Token t){		//a putback fv visszarakja argumentumát a token_stram pufferébe
	if (full) error("putback() into full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get(){

	if (full){			//ha a token pufferelve van, akkor visszaadja és továbbadja a kövinek
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch){
		case print:
		case quit:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
		case ',':
			return Token(ch);		//közvetlenül meghatározza a token típusát
		case '.':
		case '0': case '1': case '2': case '3': case '4':
    	case '5': case '6': case '7': case '8': case '9':
    	{
    		cin.putback (ch);
    		double val;
    		cin >> val;
    		return Token(number, val);
    	}
    	default: 
    	{
    		if (isalpha(ch)){
    			string s;			//kulcsszavak a deklarázióhoz, kilépéshez...
    			s += ch;
    			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
    			cin.putback(ch);
    			if (s == declkey) return Token{let};
    			else if (s == sqrtkey) return Token{square_root};
    			else if (s == powkey) return Token{cpow};
    			else if (is_declared(s))
    				return Token(number, get_value(s));
    			return Token{name,s};
    		}
    		error("Bad token");
    	}
	}
}

void Token_stream::ignore(char c){

	if (full && c == buffer.kind){		//input törlése, amíg c vagy \n nincs
		full = false;
		return;
	}
	full = false;		//pufferelt token törlése

	char ch = 0;
	while (cin>>ch)
		if (ch==c) return;
}

Token_stream ts;

double calc_sqrt(){

	char ch;
	if (cin.get(ch) && ch != '(' ) error ("'('' expected");
	cin.putback(ch);
	double d = expression();			//zárójeles kifejezés beolvasása
	if (d < 0) error("sqrt: negative value");
	return sqrt(d);
}

double primary();
double pow_to(){

	char ch;
	if (cin.get(ch) && ch != '(' ) error ("'('' expected");
	double d = primary();
	
	Token t = ts.get();
	if (t.kind != ',') error("',' expected");
	double d2 = primary();

	Token t2 = ts.get();
	if (t2.kind != ')') error("')' expected");

	return pow(d, d2);

}

double primary(){

	Token t = ts.get();
	switch (t.kind){
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error ("')' expected");
			return d;
		}
		case number:
			return t.value;
		case '-':
			return - primary();
		case '+':
			return primary();
		case square_root:
			return calc_sqrt();
		case cpow:
			return pow_to();
		case quit:
			exit(0);
		default:
			error("primary expected");
			return 0;
	}
}

double term(){

	double left = primary();
	Token t = ts.get();
	while(true){
		switch (t.kind){
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if (d == 0) error ("divide by zero");
				left /= d;
				t = ts.get();
				break;
			}
			case '%':
			{
				double d = primary();
				if (d == 0) error ("%: Zero oszto");
				left = fmod (left, d);
				t = ts.get();
				break;
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression(){

	double left = term();
	Token t = ts.get();
	while (true){
		switch(t.kind){
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

void clean_up_mess(){
	ts.ignore(print);		//adig törli az inputot, amíg print parancs nem található
}

double declaration(){
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression();
	define_name(var_name, d);
	return d;
}

double statement(){
	Token t = ts.get();
	switch(t.kind){
		case let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}

void calculate(){


	while (cin)
	try {
		Token t = ts.get();
		while (t.kind == print) t = ts.get();		//eltávolítja a print parancsokat
		if (t.kind == quit) return;
		ts.putback(t);
		cout << "=" << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess();		//kitörli a fennmaradt bevitelt és újra a felhasználótól kér
	}
}

int main() 

try {

	define_name("pi", 3.1415926535);
	define_name("e", 2.7182818284);
	calculate();

	return 0;
} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "exception\n";
	return 2;
}
