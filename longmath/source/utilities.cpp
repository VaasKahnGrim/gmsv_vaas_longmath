//utilities.cpp contians utility functions used in the module.
//Below is a PrintMSG(); function for printing to the server/client console.

#include "GarrysMod/Lua/Interface.h"

using namespace GarrysMod::Lua;	

#ifdef _WIN32
	#include<windows.h>
	#include<libloaderapi.h>

	typedef void(*msg_fn)(const char* msg, int r, int g, int b);
	static msg_fn msg = (msg_fn)GetProcAddress(GetModuleHandleA("tier0.dll"), "Msg");
#elif linux
	#include<linux shit for this>
#endif
