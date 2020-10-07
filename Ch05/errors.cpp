#include "std_lib_facilities.h"

int main()
try{
	cout << "Success!\n";			//Cout << "Success!\n";
	cout << "Success!\n";			//cout << "Success!\n;
	cout << "Success" << "!\n";		//cout << "Success" << !\n"
	cout << "success" << '\n';		//cout << success << '\n';
	//int res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";		//string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
	//vector<int> v(10); v[5] = 7; if (v[5]==7) cout << "Success!\n";			//vector<int> v(10); v[5] = 7; if (v(5)!=7) cout << "Success!\n";
	//if(v[5]==7) cout <<"Success!\n"; else cout <<"Fail!\n";					//if(cond) cout <<"Success!\n"; else cout <<"Fail!\n";
	//bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";	//bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
	//string s = "ape"; bool c = "fool" ; if (c) cout << "Success!\n";		//boo --> bool
	//string s = "ape"; if (s!="fool") cout << "Success!\n";					// == --> !=
	//string s = "ape"; if (s!="fool") cout << "Success!\n";					//+ --> !=; < --> <<
	//vector<char> v(5); for (int i = 0; i<v.size();++i) cout << "Success!\n"; //0<v.size --> i<v.size; nem kell ;
	//vector<char> v(5); for (int i=0; i<=v.size(); ++i) cout << "Success!\n";	//; nem kell
	//string s = "Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i];		//i<6 --> i<v.size()
	if(true) cout << "Success!\n"; else cout << "Fail!\n";						//then nem kell
	//int x = 2000; int c = x; if (c==2000) cout <<"Success!\n";					// char --> int
	//string s = "Success!\n"; for (int i = 0; i<s.size(); ++i) cout << s[i];		//i<10 --> i<s.size()
	vector<int> v(5); for (int i=0; i <=v.size(); ++i) cout<< "Success!\n";			//vector után kell <int>
	//int i =0; int j=9; while (i<10) ++i; if (j<i) cout << "Success!\n";				//++j --> ++i
	//int x = 2; double d = 5.0/(x-2.0); if (d==2*x+0.5) cout<<"Success!\n";			//a double miatt 5 és 2 helyett 5.0 és 2.0 kell
	string s= "Success!\n"; for (int i=0; i<s.size(); ++i) cout << s[i];			//<char> törlése, <=--> <; 10-->s.size
	int i =0; int j =9; while(i<10) ++i; if(j<i) cout << "Success!\n";				//define int=9;  ++j--> ++i
	int x = 4; double d = 5/(x-2); if (d==2*x+0.5) cout << "Success!\n";
	cout << "Success!\n";
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