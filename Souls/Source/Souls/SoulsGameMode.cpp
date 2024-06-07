// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoulsGameMode.h"
#include "SoulsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASoulsGameMode::ASoulsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
