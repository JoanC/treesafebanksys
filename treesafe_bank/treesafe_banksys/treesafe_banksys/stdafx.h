// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <signal.h>


// TODO: reference additional headers your program requires here

extern "C"{
	//mid debug information
#define DEBUG_MID_INFO

	//net debug information
#define DEBUG_NET_INFO

	//db debug information
#define DEBUG_DB_INFO

	//frame debug information
#define DEBUG_FRAME_INFO
}