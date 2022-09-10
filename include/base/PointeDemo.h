#include "stdafx.h"

struct Pod {
    int x;
};

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

	void MakeMemoryLeak()
	{
		// CRT report OK
		Pod* pPod = DBG_NEW Pod;
		pPod = DBG_NEW Pod; // Oops, leaked the original pPod!
		delete pPod;

		// CRT REPORT NG: file name line number is missing 
		void *a = malloc(sizeof(int) * 10) ;
		// TODO: how to write a macro like GDB_NEW to report the line that made the allocation 
			
		_CrtDumpMemoryLeaks();
	}
};