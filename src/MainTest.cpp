#include <DLstdc.h>

// Tutorial
#include <DLpointer.h>
#include "DesignPattern.h"

int main()
{
// atoi demo
	/*const DLchar*  x = (const DLchar*)"123";
	int test_x = Dstdc_atoi( x );
	std::cout << test_x << std::endl;*/

// smart pointer demo
	//check_smart_ptr();

// Singalton demo
/*	std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";   
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();*/

// Factory method demo
	/*DilverFactory *dilver = new DilverFactory();
	std::cout << dilver->DilverMethod(1)->Operation() << std::endl;
	std::cout << dilver->DilverMethod(0)->Operation() << std::endl;
	delete dilver;*/

// Template method demo
	SubClass1 *subclass1_ = new SubClass1();
	ClientCode(subclass1_);
	std::cout << std::endl;
	SubClass2 *subclass2_ = new SubClass2();
	ClientCode(subclass2_);
}