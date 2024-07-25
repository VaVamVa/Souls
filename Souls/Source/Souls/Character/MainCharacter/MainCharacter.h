// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "MainCharacter.generated.h"

class UControllerInputComp;

/**
 * 
 */
UCLASS()
class SOULS_API AMainCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	

	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<UControllerInputComp> ControllerInputComp;

public:
	AMainCharacter();

protected:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	virtual void Tick(float DeltaTime) override;


};
