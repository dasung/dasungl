#include "stdafx.h"


#ifdef _DEBUG
   #ifndef DBG_NEW
      #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
      #define new DBG_NEW
   #endif
#endif  

#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

class PointerDemo
{
public:
	int FindBUfferLength( const char* buffer )
	{
		int len = 0;

		while( *buffer )
		{
			++buffer;
			++len;
		}

		return len;
	}

	// Not sucess have to check CRT libarary usage
	void MakeMemoryLeak()
	{
		void *a = malloc(sizeof(int) * 10) ;
	}
};