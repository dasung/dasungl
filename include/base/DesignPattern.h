#include "stdafx.h"

#include <thread>
#include <mutex>

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
}

void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->Value() << "\n";
}