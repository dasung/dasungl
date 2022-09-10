#include <DLstdc.h>

// Tutorial
#include <DLpointer.h>
#include "DesignPattern.h"
#include "VirtualDemo.h"
#include "PointeDemo.h"
#include "GraphAlgo.h"
#include "CopyConstructDemo.h"
#include "MoveConstructor.h"

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
	/*SubClass1 *subclass1_ = new SubClass1();
	ClientCode(subclass1_);
	std::cout << std::endl;
	SubClass2 *subclass2_ = new SubClass2();
	ClientCode(subclass2_);*/

// Virtual demo
	/*Base *obj1 = new Base();
	Base *obj2 = new Derived();
	Derived *obj3 = new Derived();

	obj1->func2();
	obj2->func2();
	
	obj3->func1();

	obj1->func4("");
	obj2->func4("Because 'virtual' is missing...");
	obj3->func4();

	DerivedDemo *obj4 = new DerivedDemo();
	obj4->func5();
	obj4->func4("Just called using Derived class instance type...");

	delete obj1, obj2, obj3, obj4;*/

// Pointer demo
	PointerDemo p;
	char *buffer = "Hello world!";
	p.MakeMemoryLeak();

	std::cout << p.FindBUfferLength( buffer ) << std::endl;

// Graph demo
	//GraphAdjMatrix g1(5);
	//GraphAdjList g2;

// Copy construct DEMO
	/*Line line( 10 );
	DisplayPassByValue( line );
	DisplayAssignment(line);
	DisplayPassByReference( line );*/

// Move construct DEMO
 
    /*std::vector<MoveConstructor> vec;
    vec.push_back(MoveConstructor(10));	// Move constructor
	std::cout << "\n********************\n";
	vec.push_back(MoveConstructor(20)); // Move constructor
	std::cout << "\n********************\n";
	vec.push_back(MoveConstructor(30)); // Move constructor
	std::cout << "\n********************\n";
	MoveConstructor m( 44 );
	vec.push_back( m );	// Copy constructor
	std::cout << "\n********************\n";*/

}