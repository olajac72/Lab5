#pragma once
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Point2D
{
private:
	float x, y;

public:
	Point2D(int x, int y);
	Point2D();
	Point2D(const Point2D& p2d);
	float Distance(Point2D p2d);
	string toString();

	Point2D operator+(const Point2D& p2d);
	bool operator==(const Point2D& p2d);
	Point2D& operator=(const Point2D& p2d);
};