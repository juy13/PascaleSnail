#include "stdafx.h"
#include "PascaleSnailClass.h"


PascaleSnailClass::PascaleSnailClass()
{
}


PascaleSnailClass::~PascaleSnailClass()
{
}

std::ostream & operator<<(std::ostream & out, const Point & point)
{
	out << "X: " << point.x << " Y: " << point.y << std::endl;
	return out;
}
