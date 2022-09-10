// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <algorithm>
#include <memory>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <list>
#include <set>
#include <sstream>
#include <sys/stat.h>
#include <vector>
#include <Windows.h>

#if !defined GENERATE_ERROR_LIST
#include <codecvt>
#include <tchar.h>
#endif


#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
    #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
    // Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
    // allocations to be of _CLIENT_BLOCK type
#else
    #define DBG_NEW new
#endif