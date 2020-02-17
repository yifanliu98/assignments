#include<iostream>
#include<cmath>
#define _USE_MATH_DEFINE
using namespace std;

class Point
{
public:
	Point();
	Point(double x, double y);
	void move_horizontally(double num);
	void move_vertically(double num);
	double distance_between(Point pt);

private:
	double X;
	double Y;
};
Point::Point()
{
	X=0;
	Y=0;
}
Point::Point(double x,double y)
{
	X=x;
	Y=y;
}
void Point::move_horizontally(double num)
{
	X +=num;
}
void Point::move_vertically(double num)
{
	Y +=num;
}
double Point::distance_between(Point pt)
{
	double temp=sqrt(pow(X-pt.X,2)+pow(Y-pt.Y,2));
	return temp;
}


int main()
{
	Point pt1(2,4),pt2(3,5);
	cout<<pt1.distance_between(pt2)<<endl;
	system("PAUSE");
	return 0;
}