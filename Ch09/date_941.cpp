#include "std_lib_facilities.h"

struct Date
{
	int y;
	int m;
	int d;
};

Date today;
Date tomorrow;

void init_day(Date& date, int y, int m, int d)
{
	if (y > 0)
		date.y = y;
	else
		error("Invalid year");
	if (m <= 12 && m > 0)
		date.m = m;						//ekkor valid, felveheti az értéket
	else
		error("Invalid month");
	if (d > 0 && d <=31)
		date.d = d;
	else
		error("Invalid day");

}

void add_day(Date& dd, int n)
{
	dd.d += n;
	if (dd.d > 31);
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.y 
				<< ',' << d.m
				<< ',' << d.d << ')';
}
	
int main()
try {
	
	Date today;
	init_day(today, 1978, 6, 25);
	Date tomorrow = today;
	add_day(tomorrow, 1);

	cout << "Today: " << today << endl;
	cout << "Tomorrow: " << tomorrow << endl;

	//Date bad_day;
	//init_day(bad_day, 2004, 13, -5);

	return 0;

} catch (exception& e) {
	cout << e.what() << endl;
	return 1;
}