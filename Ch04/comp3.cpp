#include "std_lib_facilities.h"
int main()
{
	double number = 0, smallest = 0, largest = 0, convert = 0;
	
	string unit;
	
	const double m_to_cm = 100;
	const double in_to_cm = 2.54;
	const double ft_to_in = 12;
	const double cm_to_m = 0.01;
	
	vector<double> distances;								//értékek eltárolása a vectorban
	
	cout << "Please enter a number and a measurement unit (cm, m, in, ft)!" << endl;
	
	while (cin >> number >> unit)
	{
		if (unit != "cm" && unit != "ft" && unit != "in" && unit != "m")
		{
			cout << "This is an invalid unit. Please enter a number and a valid unit!" << endl;
		}
		else
		{
			cout << "You entered this: " << number << unit << endl;
			
			if (unit == "m")
			{
			convert = number;
			}
			else if (unit == "in")
			{
			convert = (number * in_to_cm) * cm_to_m;
			}
			else if (unit == "ft")
			{
			convert = (number * ft_to_in) * in_to_cm * cm_to_m;
			}
			else if (unit == "cm")
			{
			convert = number * cm_to_m;
			}
			
			distances.push_back(convert);						//a méterré alakított értékek hozzáadása a vectorhoz
			
			if (largest == 0 && smallest == 0)
			{
				largest = number;
				smallest = number;
				
				cout << "The smallest so far: " << smallest << unit << endl;
				cout << "The largest so far: " << largest << unit <<endl;
			}
			else if (convert > smallest)
			{
				largest = number;
				
				cout << "The smallest so far: " << smallest << unit << endl;
				cout << "The largest so far: " << largest << unit << endl; 
			}
		}
	}
	
	sort(distances);									//a vector elemeinek rendezése

	double sum = 0;
	
	for(double distance : distances)
	{
		sum += distance;
		cout << distance << endl;
	}
	
	cout << "The sum of the values: " << sum << endl;
	cout << "The smallest value: " << distances[0] << endl;					//első (0.) elem kiírása
	cout << "The largest value: " << distances[distances.size()-1] << endl;			//utolsó elem kiírása

return 0;
}
