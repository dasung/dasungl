#include "stdafx.h"

class MoveConstructor {
private:
    int *data;  // raw pointer
public:
    void MoveConstructorPrint( const MoveConstructor &dest );

    MoveConstructor(int d);   // Constructor
    MoveConstructor(const MoveConstructor &source);  // Copy Constructor
    MoveConstructor(MoveConstructor &&source);  // Move Constructor
    ~MoveConstructor();  // Destructor
};


MoveConstructor::MoveConstructor( int d )
{
	std::cout << "Normal constructor allocating ptr " << d << std::endl;

	data = new int;
	*data = d;
}

// Copy Constructor
MoveConstructor::MoveConstructor(const MoveConstructor &source)
{
	std::cout << "Calling Copy constructor\n";
	data = new int;
	*data = *source.data;
}

// Move contrctor
MoveConstructor::MoveConstructor(MoveConstructor &&source) 
								: data( source.data )
{
	std::cout << "Calling Move constructor" << *(this->data) << std::endl;
    source.data = nullptr;  // Steal the data and then null out the source pointer
}

MoveConstructor::~MoveConstructor()
{
	std::cout << "Freeing memory!" << std::endl;
	delete data;
}

void MoveConstructor::MoveConstructorPrint( const MoveConstructor &dest )
{
	std::cout << "Print---> " << *dest.data << std::endl;
}


