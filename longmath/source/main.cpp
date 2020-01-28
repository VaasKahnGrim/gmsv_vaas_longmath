#include "GarrysMod/Lua/Interface.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "stdint.h"
#ifdef DEBUG
	#include "utilities.cpp"
#endif
using namespace GarrysMod::Lua;

//
// TO DO: Convert all instances of LUA_FUNCTION
//


//
// Basic Math
//
LUA_FUNCTION(vaas_lm_add){
	LUA->CheckType(1,GarrysMod::Lua::Type::STRING);
	LUA->CheckType(2,GarrysMod::Lua::Type::STRING);
	uint64_t SID = std::stoull(LUA->GetString(1));
	uint64_t SID_2 = std::stoull(LUA->GetString(2));
	uint64_t Out = SID+SID_2;

	//If you want to do validation of the value returned, you are on your own.

	//if(!Out){
		//LUA->PushBool(false);
	//}else if(Out > 18446744073709551615){
		//printMessage(LUA,"Overflow Prevented, returning maximum value inside.\n",0,255,0);
		//LUA->PushString("18446744073709551615");
	//}else{
		LUA->PushString(std::to_string(Out).c_str());
	//}
	return 1;
}

LUA_FUNCTION(vaas_lm_subtract){
	LUA->CheckType(1,GarrysMod::Lua::Type::STRING);
	LUA->CheckType(2,GarrysMod::Lua::Type::STRING);
	uint64_t SID = std::stoull(LUA->GetString(1));
	uint64_t SID_2 = std::stoull(LUA->GetString(2));
	uint64_t Out = SID-SID_2;

	//If you want to do validation of the value returned, you are on your own.

	//if(!Out){
		//LUA->PushBool(false);
	//}else if(Out > 18446744073709551615){
		//printMessage(LUA,"Overflow Prevented, returning maximum value inside.\n",0,255,0);
		//LUA->PushString("18446744073709551615");
	//}else{
		LUA->PushString(std::to_string(Out).c_str());
	//}
	return 1;
}

LUA_FUNCTION(vaas_lm_multiply){
	LUA->CheckType(1,GarrysMod::Lua::Type::STRING);
	LUA->CheckType(2,GarrysMod::Lua::Type::STRING);
	uint64_t SID = std::stoull(LUA->GetString(1));
	uint64_t SID_2 = std::stoull(LUA->GetString(2));
	uint64_t Out = SID*SID_2;

	//If you want to do validation of the value returned, you are on your own.

	//if(!Out){
		//LUA->PushBool(false);
	//}else if(Out > 18446744073709551615){
		//printMessage(LUA,"Overflow Prevented, returning maximum value inside.\n",0,255,0);
		//LUA->PushString("18446744073709551615");
	//}else{
		LUA->PushString(std::to_string(Out).c_str());
	//}
	return 1;
}

LUA_FUNCTION(vaas_lm_divide){
	LUA->CheckType(1,GarrysMod::Lua::Type::STRING);
	LUA->CheckType(2,GarrysMod::Lua::Type::STRING);
	uint64_t SID = std::stoull(LUA->GetString(1));
	uint64_t SID_2 = std::stoull(LUA->GetString(2));
	uint64_t Out = SID/SID_2;

	//If you want to do validation of the value returned, you are on your own.

	//if(!Out){
		//LUA->PushBool(false);
	//}else if(Out > 18446744073709551615){
		//printMessage(LUA,"Overflow Prevented, returning maximum value inside.\n",0,255,0);
		//LUA->PushString("18446744073709551615");
	//}else{
		LUA->PushString(std::to_string(Out).c_str());
	//}
	return 1;
}

//
// Basic Math but for Vectors
//
LUA_FUNCTION(vaas_lm_vec_add){
	LUA->CheckType(1,GarrysMod::Lua::Type::VECTOR);
	Vector vec1 = LUA->GetVector(1);
	Vector vec2 = LUA->GetVector(2);
	Vector vec_out;
	vec_out.x = vec1.x+vec2.x;
	vec_out.y = vec1.y+vec1.y;
	vec_out.z = vec1.z+vec2.z;
	LUA->PushVector(vec_out);
	return 1;
}

LUA_FUNCTION(vaas_lm_vec_sub){
	LUA->CheckType(1,GarrysMod::Lua::Type::VECTOR);
	LUA->CheckType(2,GarrysMod::Lua::Type::VECTOR);
	Vector vec1 = LUA->GetVector(1);
	Vector vec2 = LUA->GetVector(2);
	Vector vec_out;
	vec_out.x = vec1.x-vec2.x;
	vec_out.y = vec1.y-vec1.y;
	vec_out.z = vec1.z-vec2.z;
	LUA->PushVector(vec_out);
	return 1;
}

LUA_FUNCTION(vaas_lm_vec_multiply){
	LUA->CheckType(1,GarrysMod::Lua::Type::VECTOR);
	LUA->CheckType(2,GarrysMod::Lua::Type::VECTOR);
	Vector vec1 = LUA->GetVector(1);
	Vector vec2 = LUA->GetVector(2);
	Vector vec_out;
	vec_out.x = vec1.x*vec2.x;
	vec_out.y = vec1.y*vec1.y;
	vec_out.z = vec1.z*vec2.z;
	LUA->PushVector(vec_out);
	return 1;
}

LUA_FUNCTION(vaas_lm_vec_divide){
	LUA->CheckType(1,GarrysMod::Lua::Type::VECTOR);
	LUA->CheckType(2,GarrysMod::Lua::Type::VECTOR);
	Vector vec1 = LUA->GetVector(1);
	Vector vec2 = LUA->GetVector(2);
	Vector vec_out;
	vec_out.x = vec1.x/vec2.x;
	vec_out.y = vec1.y/vec1.y;
	vec_out.z = vec1.z/vec2.z;
	LUA->PushVector(vec_out);
	return 1;
}


void Vaas_LongMath_init(GarrysMod::Lua::ILuaBase* LUA){
	#ifdef DEBUG
	msg("Vaas LongMath module loaded.\n",0,255,0);
	#endif
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
		LUA->CreateTable();
			//basic math
			LUA->PushCFunction(vaas_lm_add);
			LUA->SetField(-2,"add");
			LUA->PushCFunction(vaas_lm_subtract);
			LUA->SetField(-2,"sub");
			LUA->PushCFunction(vaas_lm_multiply);
			LUA->SetField(-2,"multiply");
			LUA->PushCFunction(vaas_lm_divide);
			LUA->SetField(-2,"divide");

			//Vectors
			LUA->PushCFunction(vaas_lm_vec_add);
			LUA->SetField(-2,"vec_add");
			LUA->PushCFunction(vaas_lm_vec_sub);
			LUA->SetField(-2,"vec_sub");
			LUA->PushCFunction(vaas_lm_vec_multiply);
			LUA->SetField(-2,"vec_multiply");
			LUA->PushCFunction(vaas_lm_vec_divide);
			LUA->SetField(-2,"vec_divide");
		LUA->SetField(-1,"longmath");
	LUA->Pop();
}

// Called when you module is opened
GMOD_MODULE_OPEN(){
	Vaas_LongMath_init(LUA);
	return 0;
}

// Called when your module is closed
GMOD_MODULE_CLOSE(){
	#ifdef DEBUG
		msg("Vaas LongMath module nolonger in use, unloading.\n",0,255,0);
	#endif
	return 0;
}
