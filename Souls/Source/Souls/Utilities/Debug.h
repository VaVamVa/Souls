#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_CLASS(CustomDebuggingLog, Log, All)

#define STRINGIFY(x) #x
#define CALL_INFO FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")")

class Debug
{
private:

public:
	static void CallLineInfo(FString Info)
	{
		UE_LOG(OnlyDebuggingLog, Log, TEXT("%s"), *Info);
	}
};