#pragma once
#include <stdio.h>
#include <iostream>

typedef struct Point
{
	double x, y;
	Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	friend std::ostream & operator<<(std::ostream & out, const Point &point);
}Point;

class PascaleSnailClass
{
private:
	double a;
	double l;

public:
	PascaleSnailClass();
	~PascaleSnailClass();
};

