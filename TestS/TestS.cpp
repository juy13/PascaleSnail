// TestS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "..\PascaleSnailClass\PascaleSnailClass.h"
#include "gtest/gtest.h"

TEST(PSConstractor, DefaultConstructor)
{
	PascaleSnailClass a;
	ASSERT_EQ(3, a.get_l());
	ASSERT_EQ(2, a.get_a());

	PascaleSnailClass a1(2, 4);
	ASSERT_EQ(4, a1.get_l());
	ASSERT_EQ(2, a1.get_a());
}

TEST(PSConstructor, ExceptionInConstructor)
{
	ASSERT_ANY_THROW(PascaleSnailClass a3(-1, 0));
}

TEST(PSSeters, Set_RASet_C)
{
	PascaleSnailClass a3;
	ASSERT_ANY_THROW(a3.set_l(-3));
	ASSERT_ANY_THROW(a3.set_a(0));
}

TEST(PSSeters2, Set_RASet_C)
{
	ASSERT_ANY_THROW(PascaleSnailClass a3(-1, 2));
}

TEST(PSGeters, Get_CAGet_R)
{
	PascaleSnailClass a3(2, 5.6);
	ASSERT_EQ(2, a3.get_a());
	ASSERT_EQ(5.6, a3.get_l());
}

TEST(PSDefault, AnotherFunc)
{
	PascaleSnailClass a3(7, 4);
	const double err = 0.0001;
	ASSERT_EQ(7, a3.get_a());
	ASSERT_EQ(4, a3.get_l());
	double ro;
	double ra;
	double rc;
	a3.RadCurv(ra, rc, ro);
	ASSERT_NEAR(6.72222, ra, err);
	ASSERT_NEAR(0.9000, rc, err);
	ASSERT_NEAR(2.8722, ro, err);
	ASSERT_NEAR(6.8684, a3.Rad2Cent(30), err);
	ASSERT_NEAR(399.7189, a3.Sq(), err);
	ASSERT_STREQ("(x^2 + y^2 + 7.00*y)^2 = 16.00(x^2 + y^2)", a3.Eq());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
