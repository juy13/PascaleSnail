#pragma once
#include <stdio.h>
#include <iostream>
#include <string>

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
	std::string state;


public:
	PascaleSnailClass(double a = 1, double l = 1);
	~PascaleSnailClass();

	/* Setters */
	void set_a(double a);
	void set_l(double l);


	/* Getters */
	std::string get_type() const;
	double get_a() const;
	double get_l() const;

	void RadCurv(double &Ra, double &Rc, double &Ro) const;
	double Sq() const;
	double Rad2Cent(double fi) const;
	char* Eq() const;

};

