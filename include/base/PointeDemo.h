#include "stdafx.h"

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
};