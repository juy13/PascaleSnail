#define _USE_MATH_DEFINES 
#include "PascaleSnailClass.h"
#include <cmath>


PascaleSnailClass::PascaleSnailClass(double a, double l)
{
	if (a <= 0 || l <= 0)
		throw std::exception("Illegol a or l");
	else
	{
		this->a = a;
		this->l = l;
		if (a > l)
			this->state = "With a loop";
		if (a = l)
			this->state = "Cardioid";
		if (a < l)
			this->state = "Oval";

	}
}


PascaleSnailClass::~PascaleSnailClass()
{
}

void PascaleSnailClass::set_a(double a)
{
	if (a <= 0)
		throw std::exception("Illegal a");
	else
		this->a = a;
}

void PascaleSnailClass::set_l(double l)
{
	if (l <= 0)
		throw std::exception("Illegal l");
	else
		this->l = l;
}

std::string PascaleSnailClass::get_type() const
{
	return this->state;
}

double PascaleSnailClass::get_a() const
{
	return this->a;
}

double PascaleSnailClass::get_l() const
{
	return this->l;
}

void PascaleSnailClass::RadCurv(double & Ra, double & Rc, double & Ro) const
{
	double ra = pow((this->a + this->l), 2) / (this->l + 2 * this->a);
	double rc = pow((this->l - this->a), 2) / abs(this->l - 2 * this->a);
	double ro = (this->l * sqrt(pow(this->l, 2) - pow(this->a, 2))) / (2.0 * a);
	Ra = ra;
	Rc = rc;
	Ro = ro;
}

double PascaleSnailClass::Sq() const
{
	double s = ((0.5 * pow(this->a, 2)) + pow(this->l, 2)) * M_PI;
	if (this->l >= this->a)
	{		
		return s;
	}
	if (this->l < this->a)
	{
		double fi1 = std::acos((float)((- this->l) / this->a));
		double fi2 = acos(this->l / this->a);

		double s1 = s * fi1 + ((3.0 / 2.0) * this->l * (sqrt(pow(this->a, 2) - pow(this->l, 2))));
		double s2 = s * fi2 - ((3.0 / 2.0) * this->l * (sqrt(pow(this->a, 2) - pow(this->l, 2))));

		return (s1 + s2);
	}
}

double PascaleSnailClass::Rad2Cent(double fi) const
{
	if (fi < 0)
		throw std::exception("illegal fi"); 
	double ro = this->l - this->a * sin(fi * 180.0 / M_PI);
	return ro;
}

char* PascaleSnailClass::Eq() const
{
	char *formule;
	std::string point = ".";
	std::string eq;
	std::string eq1 = "(x^2 + y^2 + ";
	//float a = this->a;
	std::string eq2 = std::to_string(((float)this->a));
	std::size_t pl = eq2.find(point);
	eq2.erase(pl + 2, 4);
	std::string eq3 = "*y)^2 = ";
	std::string eq4 = std::to_string(((float)pow(this->l, 2)));
	std::size_t p2 = eq4.find(point);
	eq4.erase(p2 + 2, 4);
	std::string eq5 = "(x^2 + y^2)";
	eq.append(eq1);
	eq.append(eq2);
	eq.append(eq3);
	eq.append(eq4);
	eq.append(eq5);

	formule = new char[eq.length() + 1];
	memcpy(formule, eq.c_str(), eq.length());
	formule[eq.length()] = '\0';
	//strcpy_s(formule, eq.c_str());

	return formule;
}

std::ostream & operator<<(std::ostream & out, const Point & point)
{
	out << "X: " << point.x << " Y: " << point.y << std::endl;
	return out;
}
