#include "GarrysMod/Lua/Interface.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "stdint.h"
#include "utilities.cpp"

using namespace GarrysMod::Lua;

LUA_FUNCTION(vaas_lm_add){
	LUA->CheckType(1,GarrysMod::Lua::Type::STRING);
	LUA->CheckType(2,GarrysMod::Lua::Type::STRING);
	uint64_t SID = std::stoull(LUA->GetString(1));
	uint64_t SID_2 = std::stoull(LUA->GetString(2));
	uint64_t Out = SID + SID_2;
	if(!Out){
		LUA->PushBool(false);
	}else if(Out > 18446744073709551615){
		printMessage(LUA,"Overflow Prevented, returning maximum value inside.\n",0,255,0);
		LUA->PushString("18446744073709551615");
	}else{
		LUA->PushString(std::to_string(Out).c_str());
	}
	return 1;
}

LUA_FUNCTION(vaas_lm_subtract){
	LUA->CheckType(1,GarrysMod::Lua::Type::STRING);
	LUA->CheckType(2,GarrysMod::Lua::Type::STRING);
	uint64_t SID = std::stoull(LUA->GetString(1));
	uint64_t SID_2 = std::stoull(LUA->GetString(2));
	uint64_t Out = SID - SID_2;
	if(!Out){
		LUA->PushBool(false);
	}else if(Out > 18446744073709551615){
		printMessage(LUA,"Overflow Prevented, returning maximum value inside.\n",0,255,0);
		LUA->PushString("18446744073709551615");
	}else{
		LUA->PushString(std::to_string(Out).c_str());
	}
	return 1;
}

LUA_FUNCTION(vaas_lm_multiply){
	LUA->CheckType(1,GarrysMod::Lua::Type::STRING);
	LUA->CheckType(2,GarrysMod::Lua::Type::STRING);
	uint64_t SID = std::stoull(LUA->GetString(1));
	uint64_t SID_2 = std::stoull(LUA->GetString(2));
	uint64_t Out = SID * SID_2;
	if(!Out){
		LUA->PushBool(false);
	}else if(Out > 18446744073709551615){
		printMessage(LUA,"Overflow Prevented, returning maximum value inside.\n",0,255,0);
		LUA->PushString("18446744073709551615");
	}else{
		LUA->PushString(std::to_string(Out).c_str());
	}
	return 1;
}

LUA_FUNCTION(vaas_lm_divide){
	LUA->CheckType(1,GarrysMod::Lua::Type::STRING);
	LUA->CheckType(2,GarrysMod::Lua::Type::STRING);
	uint64_t SID = std::stoull(LUA->GetString(1));
	uint64_t SID_2 = std::stoull(LUA->GetString(2));
	uint64_t Out = SID / SID_2;
	if(!Out){
		LUA->PushBool(false);
	}else if(Out > 18446744073709551615){
		printMessage(LUA,"Overflow Prevented, returning maximum value inside.\n",0,255,0);
		LUA->PushString("18446744073709551615");
	}else{
		LUA->PushString(std::to_string(Out).c_str());
	}
	return 1;
}


void Vaas_LongMath_init(GarrysMod::Lua::ILuaBase* LUA){
	printMessage(LUA,"Vaas LongMath module loaded.\n",0,255,0);
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
		LUA->PushCFunction(vaas_lm_add);
		LUA->SetField(-2,"longmath_add");
		LUA->PushCFunction(vaas_lm_subtract);
		LUA->SetField(-2,"longmath_subtract");
		LUA->PushCFunction(vaas_lm_multiply);
		LUA->SetField(-2,"longmath_multiply");
		LUA->PushCFunction(vaas_lm_divide);
		LUA->SetField(-2,"longmath_divide");
	LUA->Pop();
}

// Called when you module is opened
GMOD_MODULE_OPEN(){
	Vaas_LongMath_init(LUA);
	return 0;
}

// Called when your module is closed
GMOD_MODULE_CLOSE(){
	printMessage(LUA,"Vaas LongMath module nolonger in use, unloading.\n",0,255,0);
	return 0;
}
