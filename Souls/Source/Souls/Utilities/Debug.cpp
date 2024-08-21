#include "Debug.h"


DEFINE_LOG_CATEGORY(CustomDebuggingLog)

void Debug::Log(FString Message)
{
	UE_LOG(CustomDebuggingLog, Type::Log, TEXT("%s"), *Message);
}

void Debug::Warning(FString Message)
{
	UE_LOG(CustomDebuggingLog, Type::Warning, TEXT("%s"), *Message);
}

void Debug::Error(FString Message)
{
	UE_LOG(CustomDebuggingLog, Type::Error, TEXT("%s"), *Message);
}

void Debug::CheckBool(FString Variable, bool InBool)
{
	UE_LOG(CustomDebuggingLog, Type::Display, TEXT("'%s' is  %s"), *Variable, InBool ? "True" : "False");
}

void Debug::CheckInt(FString Variable, int InInt)
{
	UE_LOG(CustomDebuggingLog, Type::Display, TEXT("'%s' is  %d"), *Variable, InInt);
}

void Debug::CheckFloat(FString Variable, float InFloat, uint32 Decimal)
{
	if (Decimal > 6) Decimal = 6;

	UE_LOG(CustomDebuggingLog, Type::Display, TEXT("'%s' is  %.*f"), *Variable, Decimal, InFloat);
}

void Debug::CheckVector3(FString Variable, FVector InVector, uint32 Decimal)
{
	if (Decimal > 6) Decimal = 6;

	UE_LOG(CustomDebuggingLog, Type::Display, TEXT("'%s' is  ( X= %.*f, Y= %.*f, Z= %.*f )"), *Variable, Decimal, InVector.X, Decimal, InVector.Y, Decimal, InVector.Z);
}

void Debug::PrintOnScreen(FString Message, int Key, float Time, FColor Color)
{
	if (GEngine->IsValidLowLevelFast())
	{
		GEngine->AddOnScreenDebugMessage(Key, Time, Color, Message);
		return;
	}
	
	Warning("GEngine is not valid");
}

void Debug::PrintOnScreen(Param_PrintOnScreen& Param)
{
	if (GEngine->IsValidLowLevelFast())
	{
		GEngine->AddOnScreenDebugMessage(Param.Key, Param.Time, Param.Color, Param.Message, Param.bNewerOnTop);
		return;
	}

	Warning("GEngine is not valid");
}
