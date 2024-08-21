#pragma once

#include "CoreMinimal.h"


DECLARE_LOG_CATEGORY_EXTERN(CustomDebuggingLog, Type::Log, All)

#define STRINGYFY(x) #x

#define CURRENT_INFO FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")")
#define LOG_THIS_LINE UE_LOG(CustomDebuggingLog, Type::Log, TEXT("%s"), *(CURRENT_INFO))
#define WARNING_THIS_LINE UE_LOG(CustomDebuggingLog, Type::Warning, TEXT("%s"), *(CURRENT_INFO))
#define CHECK()

namespace Debug
{

#pragma region Screen_Debug_Message
	struct Param_PrintOnScreen
	{
		FString Message = "";
		int Key = 0;
		float Time = 1.0f;
		FColor Color = FColor::Cyan;
		bool bNewerOnTop = true;
	};

	void PrintOnScreen(FString Message, int Key = 0, float Time = 1.0f, FColor Color = FColor::Cyan);
	void PrintOnScreen(Param_PrintOnScreen& Param);
#pragma endregion Screen_Debug_Message


#pragma region UE_LOG_Message
	void Log(FString Message);
	
	void Warning(FString Message);

	void Error(FString Message);

	void CheckBool(FString Variable, bool InBool);
	void CheckInt(FString Variable, int InInt);
	void CheckFloat(FString Variable, float InFloat, uint32 decimal = 4);
	void CheckVector3(FString Variable, FVector InVector, uint32 Decimal = 4);
#pragma endregion UE_LOG

};
