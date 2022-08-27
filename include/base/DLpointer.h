#include "stdafx.h"

/***  Define Smart Pointers  ***/

/** @brief
 * Smart pointers can do vertually everything that raw pointer can.
 * Less oppotunity of error!
 * C++11: std::auto_ptr, std::unique_ptr, std::shared_ptr, and std::weak_ptr
 *
 ** @when to use
 * All are designed to avoid resource leaks
 * If an entity should keeps the ownership of an object, use smart pointers.
 * If there is no sign of ownership, use raw pointers.
 *
 *  std::auto_ptr
 ** Deprecated
 ** Why: Inability of copying 
 *** If copy reset to rValue to null pointer
 *
 * std::unique_ptr
 ** Copying is not allwoed ( exclusive ownership )
 *** Transfer ownership using std::move() / No fake copy assignment
 ** Custom delete can be specified
 ** Easily and efficiently converts to a std::shared_ptr
 *
 * std::share_ptr
 ** Resource�fs reference count
 ** Detroys when reference count is zero
 ** Use when to share ownership of the resources
 **/


void auto_ptr_demo()
{
	std::cout << "\n-----auto_ptr_demo-----\n";
	std::auto_ptr<std::string> pSptr1(new std::string("Hello Auto Ptr"));
	std::auto_ptr<std::string> pSptr2( pSptr1 );
	std::auto_ptr<std::string> pSptr3 = pSptr2;

//	std::cout << "\t" << *pSptr1 << std::endl;  // null
//	std::cout << "\t" << *pSptr2 << std::endl;  // null
	std::cout << "\t" << *pSptr3 << std::endl;
}

struct X
{
	void foo()
	{
		std::cout << "\tStruct x is pointer auto deleted by unique_ptr";
	}
};

// Resource ownership explicitly transferred to the caller
std::unique_ptr<X> Xfactory() 
{
	std::cout << "\n-----unique_ptr_demo-----\n";

	std::unique_ptr<std::string> pstr1(new std::string("Hello Unique Ptr"));

	// Compilar error: Copying is not allwoed
	//std::unique_ptr<std::string> pstr2( pstr1 );
	//std::unique_ptr<std::string> pSptr3 = pstr2.get();

	// Move allowed
	std::string *raw_strptr = pstr1.get();

	std::cout << "\t" << *pstr1 << std::endl;
	std::cout << "\t" << *raw_strptr << std::endl;

	// Dynamically allocated instance
	return std::unique_ptr<X> ( new X );
}

class A { 
public: 
    void show() 
    { 
        std::cout << "A is shared object pointer\n"; 
    } 
};

void shared_ptr_demo()
{
	std::cout << "\n-----shared_ptr_demo-----\n";
	std::shared_ptr<A> p1(new A); 
    std::cout << p1.get() << std::endl; 
    p1->show();
    
	std::shared_ptr<A> p2(p1); 
    p2->show(); 
    
	std::cout << p1.get() << std::endl; 
    std::cout << p2.get() << std::endl; 
  
    // Returns the number of shared_ptr objects 
    // referring to the same managed object. 
    std::cout << p1.use_count() << std::endl; 
    std::cout << p2.use_count() << std::endl; 
  
    // Relinquishes ownership of p1 on the object 
    // and pointer becomes NULL 
    p1.reset(); 
    std::cout << p1.get() << std::endl; 
    std::cout << p2.use_count() << std::endl; 
    std::cout << p2.get() << std::endl;
}

void check_smart_ptr()
{
	auto_ptr_demo();

	// Dynamically allocated instance of X does not leak here
	Xfactory()->foo();

	shared_ptr_demo();
}