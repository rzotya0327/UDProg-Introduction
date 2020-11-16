#include "std_lib_facilities.h"

int main()
{
	int birth_year = 2001;
	int this_year = 2020;

	cout << "Decimal:\t\t" << dec << birth_year << endl;
	cout << "Hexadecimal:\t\t" << hex << birth_year << endl;
	cout << "Octal:\t\t\t" << oct << birth_year << endl;
	cout << "This year in decimal:\t" << dec << this_year << endl << endl;
	cout << "My age:\t\t\t" << this_year-birth_year << endl << endl;
	
	cout << showbase;

	cout << "Decimal:\t\t" << dec << birth_year << endl;
	cout << "Hexadecimal:\t\t" << hex << birth_year << endl;
	cout << "Octal:\t\t\t" << oct << birth_year << endl;

	cout << noshowbase;

	cout << '|' << setw(6) << "Zoltan" << '|' << setw(7) << "Rokonal"
		 << '|' << setw(11) << "06123456789"
		 << '|' << setw(20) << "rzotya0327@gmail.com" << "|\n";
	cout << '|' << setw(3) << "Vak" << '|' << setw(4) << "Cina"
		 << '|' << setw(11) << "06123456889"
		 << '|' << setw(18) << "bac.ilus@gmail.com" << "|\n\n";

	cout << "Enter 1234 four times!" << endl;

	int a;
    int b;
    int c;
    int d;
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << endl << endl;

	cout << 1234.56789 << "\t\t(defaultfloat)\n" << fixed
		 << 1234.56789 << "\t(fixed)\n" << scientific
		 << 1234.56789 << "\t(scientific)\n";


	return 0;
}