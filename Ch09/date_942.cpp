#include "std_lib_facilities.h"

struct Date
{
	int year, month, day;
	Date(int y, int m, int d);
	void add_day(int n);
};

Date::Date(int y, int m, int d)
{
	if (y > 0)
		year = y;					//belső tag year, month, day
	else
		error("Invalid year");
	if (m <= 12 && m > 0)
		month = m;						//ekkor valid, felveheti az értéket
	else
		error("Invalid month");
	if (d > 0 && d <=31)
		day = d;
	else
		error("Invalid day");
}

void Date::add_day(int n)
{
	day += n;
	if (day > 31);
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year 
				<< ',' << d.month
				<< ',' << d.day << ')';
}

int main()
try {
	Date today(1978, 6, 25);
	Date tomorrow = today;
	tomorrow.add_day(1);

	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;

	//Date bad_day(2004, 13, -5);

	return 0;

} catch (exception& e) {
	cout << e.what() << endl;
	return 1;
}

