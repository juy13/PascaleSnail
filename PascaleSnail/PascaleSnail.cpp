// PascaleSnail.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PascaleSnailClass.h"

int main()
{
	PascaleSnailClass a(5, 9);
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
		std::cin >> fi;
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

		double aq, l;
		std::cout << "Enter your choice to continue or press ctrl+Z to quit:" << std::endl;
		std::cout << "Input a and l: " << std::endl;
		std::cout << "\ta: ";
		std::cin >> aq;
		std::cout << "\tl: ";
		std::cin >> l;
		if (std::cin.good())
		{
			try
			{
				a.set_a(aq);
			}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}

			try
			{
				a.set_l(l);
			}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}

		}
		else
			fl1 = 0;

		//system("pause");
	}
}
