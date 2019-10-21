// PascaleSnail.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PascaleSnailClass.h"

bool getNum(double& num)
{
	double n;
	std::cin >> n;

	bool g = std::cin.good();

	if (g)
		num = n;

	return g;
}

void input_par(double &par)
{
	double a;
	while (true)
	{
		bool fl = getNum(a);
		if (fl == false)
		{
			std::cout << "Error, try again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (fl == true)
		{
			par = a;
			break;
		}
	}
}

int main()
{

	PascaleSnailClass a;
	int fl1 = 1;
	double fi = 0;
	double ro = 0;
	while (fl1)
	{
		double ro;
		double ra;
		double rc;
		std::cout << "Your figure is: " << a.get_type() << std::endl;
		a.RadCurv(ra, rc, ro);
		std::cout << "Radius of Curvature: " << std::endl << "Ra = " << ra << " Rc = " << rc << " Ro = " << ro << std::endl;
		std::cout << "Input your fi in grad: ";
		input_par(fi);
		try
		{
			std::cout << "Radius in polar system: " << a.Rad2Cent(fi) << std::endl;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}

		char *s = NULL;
		s = a.Eq();
		std::cout << "The area of snail: " << a.Sq() << std::endl;
		std::cout << "the equality: " << s << std::endl;
		delete[] s;
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		double aq, l;
		std::cout << "Enter your choice to continue:" << std::endl;
		while (true)
		{
			std::cout << "Input a and l: " << std::endl;
			std::cout << "\ta: ";
			input_par(aq);
			try
			{
				a.set_a(aq);
			}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
				continue;
			}
			std::cout << "\tl: ";
			input_par(l);
			try
			{
				a.set_l(l);
			}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
				continue;
			}
			break;
		}
		//system("pause");
	}
}
