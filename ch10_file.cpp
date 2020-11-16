#include "std_lib_facilities.h"

struct Point
{
	double x;
	double y;
};

int main()
try{

	vector<Point> original_points;
	double x;
	double y;

	for (int i = 0; i < 7; ++i)
	{
		cout << "Please enter 7 points (x,y): " << endl;
		cin >> x;
		cin >> y;
		original_points.push_back(Point{x,y}) ;
	}	
	for(Point p : original_points)
		cout << '(' << p.x << ',' << p.y << ')' << endl;

	cout << "create mydata.txt: ";
	string oname = "mydata.txt";
	ofstream ost {oname};
	if (!ost) error("cant open output file");
	for(Point p : original_points)
		ost << '(' << p.x << ',' << p.y << ')' << endl;
	
	ost.close();

	cout << "Completed!" << endl << endl;

	vector<Point> processed_points;
	string iname = "mydata.txt";
	ifstream ist {iname};
	if(!ist) error("can't open input file");
	char open_brace, comma, close_brace;
	while (ist >> open_brace >> x >> comma >> y >> close_brace)
	{
		processed_points.push_back(Point{x,y});
	}

	for(Point p : processed_points)
		cout << '(' << p.x << ',' << p.y << ')' << endl;

	ist.close();

	if(original_points.size() != processed_points.size()) error("Something is wrong!");
	for (int i = 0; i < original_points.size(); ++i)
	{
		if(original_points[i].x != processed_points[i].x) error("Something is wrong!");
		if(original_points[i].y != processed_points[i].y) error("Something is wrong!");
	}

	cout << "Result of the comparison: 2 vectors are same" << endl
		<< "original_points.size(): " << original_points.size() << endl
		<< "processed_points.size(): " << processed_points.size() << endl;

	return 0;

} catch (runtime_error& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "Some error\n";
	return 2;
}