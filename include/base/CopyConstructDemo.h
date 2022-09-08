#include "stdafx.h"

class Line 
{
   public:
      int getLength( void );
      Line( int len );             // simple constructor
      Line( const Line &obj);  // copy constructor
      ~Line();                     // destructor

   private:
      int *ptr;
};

// Member functions definitions including constructor
Line::Line(int len)
{
	std::cout << "Normal constructor allocating ptr" << std::endl;

	// allocate memory for the pointer;
	ptr = new int;
	*ptr = len;
}

// Copy Constructor
Line::Line( const Line &obj )
{
	std::cout << "Copy constructor for obj allocating ptr." << std::endl;
	
	ptr = new int;
	*ptr = ++(*obj.ptr);
}

Line::~Line()
{
	std::cout << "Freeing memory!" << std::endl;
	delete ptr;
}

int Line::getLength()
{
   return *ptr;
}

void DisplayPassByValue( Line obj )		// Copy consrtuctor is called
{
	std::cout << "\n====value pass======" << std::endl;
	std::cout << "Length of line : " << obj.getLength() << std::endl;
}

void DisplayPassByReference( Line &obj )	// Copy consrtuctor is NOT called here
{
	std::cout << "\n====reference pass======" << std::endl;
	std::cout << "Length of line : " << obj.getLength() << std::endl;
}

void DisplayAssignment( Line &obj )		// Copy consrtuctor is NOT called here
{
	std::cout << "\n====Assignment======" << std::endl;
	Line x = obj;						// Copy consrtuctor is called

	std::cout << "Length of line : " << obj.getLength() << std::endl;
}

