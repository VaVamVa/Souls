// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "BaseEnemy.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class SOULS_API ABaseEnemy : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	ABaseEnemy();

protected:
	virtual void BeginPlay() override;
};
