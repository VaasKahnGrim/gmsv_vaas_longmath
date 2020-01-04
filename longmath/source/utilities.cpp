//utilities.cpp contians utility functions used in the module.
//Below is a PrintMSG(); function for printing to the server/client console.

#include "GarrysMod/Lua/Interface.h"



using namespace GarrysMod::Lua;	

static void printMessage(GarrysMod::Lua::ILuaBase* LUA,const char* str,int r,int g,int b){
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	LUA->GetField(-1,"Color");
	LUA->PushNumber(r);
	LUA->PushNumber(g);
	LUA->PushNumber(b);
	LUA->Call(3,1);
	int ref = LUA->ReferenceCreate();
	LUA->GetField(-1,"MsgC");
	LUA->ReferencePush(ref);
	LUA->PushString(str);
	LUA->Call(2,0);
	LUA->Pop();
	LUA->ReferenceFree(ref);
}


