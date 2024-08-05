// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

class AMainCharacter;

#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class SOULS_API APlayerHUD : public AHUD
{
	GENERATED_BODY()
	
	UPROPERTY()
	TObjectPtr<AMainCharacter> MainCharacter;

public:
	APlayerHUD();

	virtual void BeginPlay() override;
	virtual void Tick(float Delta) override;

	
};
