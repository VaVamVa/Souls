// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoulsGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Widgets/PlayerHUD.h"
#include "Character/MainCharacter/MainCharacterState.h"

#include "Utilities/Helper.h"
#include "Utilities/Debug.h"

ASoulsGameMode::ASoulsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/MainCharacter/BP_MainCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;

		PlayerStateClass = Helper::GetClassFromConstructor<AMainCharacterState>("/Game/Characters/MainCharacter/BP_MainCharacterState");

		HUDClass = APlayerHUD::StaticClass();
	}

}
