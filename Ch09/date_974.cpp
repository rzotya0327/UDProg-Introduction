#include "std_lib_facilities.h"

class Year {
	static constexpr int min = 1800;			//ezen évszámok között fogadjuk el
	static constexpr int max = 2077;
public:
	class Invalid{};
	Year(int x): y(x) { if (x < min || x > max) throw Invalid{}; }
	int year() { return y; }
	void increment() { y++; }
private:
	int y;
};

Year operator++(Year& year)
{
	year.increment();
}

ostream& operator<<(ostream& os, Year year)
{
	return os << year.year();
}

const vector<string> months =
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

enum class Month {
	jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec				//be vannak vezetve, konkrét egész értékek vannak mögöttük
};

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m)+1);		//egyszerűsített if, a Month =-e decemberrel ? ha igaz ez fut : ez fut
	return m;
}

ostream& operator <<(ostream& os, Month m)			//bal oldal ostream ref, jobb oldal hónap
{
	return os << months[int(m)];
}

class Date {
	Year year;
	Month month;
	int day;					
public:									//csak ezen keresztül tudunk értéket mód.
	class Invalid {};
	Date(Year y, Month m, int d): year(y), month(m), day(d) {if(!is_valid()) throw Invalid{};} //valid-e a dátum				
	
	bool is_valid();
	void add_day(int n);
	
	Year get_year() const { return year; }
	Month get_month() const { return month; }
	int get_day() const { return day; }
};

bool Date::is_valid()
{
	if (day < 1 || day > 31) return false;

	return true;
}


void Date::add_day(int n)
{
	day += n;
	if (day > 31)
	{
		++month;					//hónap léptetése
		day -= 31;				//napból kivonjuk a hónapot
		if (month == Month::jan)
		{
			++year;
		}
	}
}

int main()
try {
	
	Date today {Year{1978}, Month::jun, 25};				

	today.add_day(1);			//1 napot léptetünk

	cout << "Date: " << today.get_year() << '.'
		<< today.get_month() << '.' << today.get_day() << endl;

	return 0;

} catch (Date::Invalid) {
	cout << "Invalid date" << endl;
	return 1;
} catch (Year::Invalid) {
	cout << "Invalid year" << endl;
	return 1;
} catch (exception& e) {
	cout << e.what() << endl;
	return 2;
}