#include "stdafx.h"

class AbstractBase
{
public:
	virtual void func1() = 0;
};

class Base 
{
public:
	virtual void func2();
	// virtual void func3(); <-- This is unresolved external as it is not implemented either base or sub class
	void func4(std::string ss);
};

void Base::func2()
{
	std::cout << "Base Implementation for virtual func2\n";
}

void Base::func4(std::string ss)
{
	std::cout << "Base func4 - " <<  ss << std::endl;
}

class Derived : public Base, AbstractBase
{
public:
	void func1();	// peo-virtual function "must be" implemented in a sub class
	void func2();	// "Not a must" as func2 already implmented in Base class
	void func4();
};

void Derived::func1()
{
	std::cout << "Implemented peo-virtual func3 \n";
}


void Derived::func2()
{
	std::cout << "Sub class Implementation for virtual func2\n";
}

void Derived::func4()
{
	std::cout << "Derived func4 calls anyway\n";
}


/*///////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////CALL BaseClass's NON VIRTUAL FUNCTIONS//////////////////
  ///////////////////////////////////////////////////////////////////////////////////////
*/

class DerivedDemo: public Base
{
public:
	using Base::func4; // make all things in Base named func4

	virtual void func5()
	{
		std::cout << "DerivedDemo func5 calls anyway\n";
	}
};