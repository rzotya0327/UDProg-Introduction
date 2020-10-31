#include "std_lib_facilities.h"

int main()
try{
	cout << "Success!\n";			//Cout << "Success!\n";			//compile-time error
	cout << "Success!\n";			//cout << "Success!\n;			//compile-time error
	cout << "Success" << "!\n";		//cout << "Success" << !\n"		//compile-time error
	cout << "success" << '\n';		//cout << success << '\n';		//compile-time error
	//int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";		//compile-time error/type  string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
	//vector<int> v(10); v[5] = 7; if (v[5]==7) cout << "Success!\n";		//complie-time and logic error  vector<int> v(10); v[5] = 7; if (v(5)!=7) cout << "Success!\n";
	//if(v[5]==7) cout <<"Success!\n"; else cout <<"Fail!\n";			//compile-time error  if(cond) cout <<"Success!\n"; else cout <<"Fail!\n";
	//bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";		//bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
	//string s = "ape"; bool c = "fool" ; if (c) cout << "Success!\n";		//compile-time error  boo --> bool
	//string s = "ape"; if (s!="fool") cout << "Success!\n";			//logicerror  == --> !=
	//string s = "ape"; if (s!="fool") cout << "Success!\n";			//compile-time error  + --> !=; < --> <<
	//vector<char> v(5); for (int i = 0; i<v.size();++i) cout << "Success!\n"; 	//logic error 0<v.size (mindig igaz lenne) --> i<v.size
	//vector<char> v(5); for (int i=0; i<=v.size(); ++i) cout << "Success!\n";	//logic error ; nem kell
	//string s = "Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i];		//logic error i<6 --> i<v.size()
	if(true) cout << "Success!\n"; else cout << "Fail!\n";				//compile-time error /then nem kell
	//int x = 2000; int c = x; if (c==2000) cout <<"Success!\n";			//narrowing error char --> int
	//string s = "Success!\n"; for (int i = 0; i<s.size(); ++i) cout << s[i];	//logic error  i<10 --> i<s.size()
	vector<int> v(5); for (int i=0; i <=v.size(); ++i) cout<< "Success!\n";		//compile-time error vector után kell <int>
	//int i =0; int j=9; while (i<10) ++i; if (j<i) cout << "Success!\n";		//logic error ++j --> ++i
	//int x = 2; double d = 5.0/(x-2.0); if (d==2*x+0.5) cout<<"Success!\n";	//narrowing error  a double miatt 5 és 2 helyett 5.0 és 2.0 kell
	string s= "Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i];		//compile-time error  <char> törlése, <=--> <; 10-->s.size
	int i =0; int j =9; while(i<10) ++i; if(j<i) cout << "Success!\n";		//logic error  define int j=9;  ++j--> ++i
	int x = 4; double d = 5/(x-2); if (d==2*x+0.5) cout << "Success!\n";		//logic error =-->==
	cout << "Success!\n";								//compile-time error
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}
