#include "std_lib_facilities.h"

class Date {
	int year, month, day;					
public:									//csak ezen keresztül tudunk értéket mód.
	Date(int y, int m, int d);				
	
	int get_month() { return month; }
	int get_day() { return day; }
	int get_year() { return year; }
	void add_day(int n);
};

Date::Date(int y, int m, int d)	
		
{
	if(y > 0)
		year = y;
	else 
		error("Invalid year");

	if (m > 1 || m < 12) 
		month = m;
	else
		error("invalid month");
	if (d > 1 || 31 > d) 
		day = d;
	else
		error("invalid day");
}

void Date::add_day(int n)
{
	day += n;
	if (day > 31);
}

ostream& operator<<(ostream& os,  Date& d)
{
	return os << '(' << d.get_year()
				<< ',' << d.get_month()
				<< ',' << d.get_day() << ')';
}

int main()
try {
	
	Date today {1978, 6, 25};	

	Date tomorrow = today;			

	tomorrow.add_day(1);			//1 napot léptetünk

	cout << "Today: " << today << endl;
	cout << "tomorrow: " << tomorrow << endl;


	return 0;

} catch (exception& e) {
	cout << e.what() << endl;
	return 1;
}