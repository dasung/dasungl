#include "stdafx.h"

#include <thread>
#include <mutex>


/*///////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////SINGLETON DEMO/////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////
*/

class Singleton
{
protected:
	std::string value_;

	Singleton(const std::string value) : value_(value)
	{
	}
private:
    static std::mutex mutex_;
	static Singleton* singleton_;

public:

    // Singletons should not be cloneable.
    Singleton(Singleton &other);

    // Singletons should not be assignable.
    Singleton operator=(const Singleton &);

	static Singleton *GetInstance(const std::string& value);

	std::string Value() const{
		return value_;
	}
};

Singleton* Singleton::singleton_ = nullptr;
std::mutex Singleton::mutex_;


Singleton* Singleton::GetInstance(const std::string& value)
{
	std::lock_guard<std::mutex> lock(mutex_);
	if(singleton_ == nullptr)
	{
		singleton_ = new Singleton(value);
	}
	return singleton_;
}

void ThreadFoo()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->Value() << "\n";
	Singleton* singleton1 = Singleton::GetInstance("YAKK");
	std::cout << singleton1->Value() << "\n";

	singleton1 = singleton;
}

void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->Value() << "\n";
}

/*///////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////FACTORY METHOD DEMO//////////////////////////////////
  // provides an interface for creating objects in a superclass, but allows subclasses to 
  alter the type of objects that will be created.
  1. Defines interface with peo virtual function
  2. Sub-class implements peo-virtual function in own way
  3. 
*/

class Logistic 
{
public:
	virtual ~Logistic() 
	{
	}
	virtual std::string Operation() const = 0;
};

class Truck : public Logistic 
{
public:
	std::string Operation() const 
	{
		return "Deliver by Land in a box";
	}
};

class Ship : public Logistic 
{
public:
	std::string Operation() const 
	{
		return "Deliver by Sea in a containder";
	}
};

class DilverFactory : public Truck, Ship
{
public:
	virtual ~DilverFactory()
	{
	}

	Logistic* DilverMethod(int type)
	{
		if( type == 0 )
			return new Truck();
		else
			return new Ship();
	}

};


/*///////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////TEMPLATE METHOD DEMO/////////////////////////////////
  /// defines the skeleton of an algorithm in the superclass but lets subclasses override 
  specific steps of the algorithm without changing its structure.

  1. Abstract class defines a TemplateMethod() with Algorotham
  2. AbstractClass should have two peo virtual functions
  3. Subclass should implement those two operation in own way
  4. write Client Method to call TemplateMethod() function
  5. main() calss Client code with needed sub class instance using Polymorphisum 
*/

class AbstractClass 
{
public:
	void TemplateMethod() const
	{
		this->BaseOperation1();
		this->BaseOperation2();
		this->RequiredOPeration1();
		this->RequiredOPeration2();
		this->Hook();
	}

protected:
	void BaseOperation1() const
	{
		std::cout << "AbstractClass says: I am doing the bulk of the work\n";
	}

	void BaseOperation2() const
	{
		std::cout << "AbstractClass says: But I let subclasses override some operations\n";
	}

	virtual void RequiredOPeration1() const = 0;
	virtual void RequiredOPeration2() const = 0;

	// Subclasses may override Hooks, but it's not mandatory. Hooks provide additional extension points in some crucial places of the algorithm.
	virtual void Hook() const {}
};

class SubClass1 : public AbstractClass
{
public:
	void RequiredOPeration1() const 
	{
		std::cout << "SubClass 1 says: Implemented Operation1\n";
	}

	void RequiredOPeration2() const 
	{
		std::cout << "SubClass 1 says: Implemented Operation2\n";
	}
};

class SubClass2 : public AbstractClass
{
public:
	void RequiredOPeration1() const 
	{
		std::cout << "SubClass 2 says: Implemented Operation1\n";
	}

	void RequiredOPeration2() const 
	{
		std::cout << "SubClass 2 says: Implemented Operation2\n";
	}
};

void ClientCode( AbstractClass *class_ )
{
	// Client dosent know how function has been implemented inside TemplateMethod()
	class_->TemplateMethod();
}