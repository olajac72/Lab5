// Point2D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Point2D.h"


int main()
{
	float dist;
	Point2D p1 (0, 0);
	Point2D p2(3, 4);
	Point2D p3;

	dist = p1.Distance(p2);
	cout << "Distance:" << dist << endl;
	
	p3 = p2;

	cout << "p3 :" << p3.toString() << endl;

	Point2D p4 = p2;

	cout << "p4 :" << p4.toString() << endl;

	Point2D p5 = p4 + p3;

	cout << "p5:" << p5.toString() << endl;

	dist = p5.Distance(p1);

	cout << "p5:" << p5.toString() << endl;

	if (p3 == p2)
		cout << "Same" << endl;
	else
		cout << "Not same" << endl;
}

Point2D::Point2D(int x, int y) : x(x), y(y)
{

}

Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::Point2D(const Point2D& p2d) // copy constructor
{
	x = p2d.x;
	y = p2d.y;
}
float Point2D::Distance(Point2D p2d)
{
	return (sqrt(pow(p2d.x,2) + pow(p2d.y,2)));
}
string Point2D::toString()
{
	string ret;

	ret = "[" + to_string(x) + "," + to_string(y) + "]";

	return ret;
}

Point2D Point2D::operator+(const Point2D& p2d)
{
	Point2D temp;

	temp.x = x + p2d.x;
	temp.y = y + p2d.y;

	return temp;
}
bool Point2D::operator== (const Point2D & p2d)
{
	if (x == p2d.x && y == p2d.y)
		return true;
	else
		return false;
}
Point2D& Point2D::operator=(const Point2D& p2d)
{
	x = p2d.x;
	y = p2d.y;
	return *this;
}