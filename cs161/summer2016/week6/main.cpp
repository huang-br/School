#include "LineSegment.hpp"

using namespace std;

int main()
{
	double x;
	double y;
	cout << "Enter a x coordinate: ";
	cin >> x;
	cout << "Enter a y coordinate: ";
	cin >> y;

	Point p1(0.0,0.0);
	Point p2(x,y);

	double dist = p1.distanceTo(p2);

	cout << "distance: " << dist <<  endl;
	
	LineSegment line(p1,p2);

	double length = line.length();
	double slope = line.slope();

	cout << "length: " << length << " slope: " << slope << endl;
	
	return 0;


}

