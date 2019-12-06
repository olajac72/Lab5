#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>
#include "SDL.h"

using namespace std;
class Point2D;

class Shape
{
protected:
	Point2D* position;
	char red, green, blue, alpha;
public:
	Shape();
	Shape(Point2D *position, char red, char green, char blue, char alpha);
	virtual void render(SDL_Renderer* render, int x, int y) = 0;
};

class Rectangle : public Shape
{
private:
	int width, height;
public:
	Rectangle();
	Rectangle(Point2D* position, char red, char green, char blue, char alpha, int width, int height);
	void render(SDL_Renderer* render, int x, int y);
};

class Triangle : public Shape
{
private:
	int base, height;
public:
	Triangle();
	Triangle(Point2D* position, char red, char green, char blue, char alpha, int base, int height);
	void render(SDL_Renderer* render, int x, int y);
};

class Circle : public Shape
{
private:
	int radius;
public:
	Circle();
	Circle(Point2D* position, char red, char green, char blue, char alpha, int radius);
	void render(SDL_Renderer* render, int x, int y);
};

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