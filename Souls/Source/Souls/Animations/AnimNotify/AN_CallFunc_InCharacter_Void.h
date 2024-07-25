// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animations/AnimNotify/AN_Base_CallFunc_ByName.h"
#include "AN_CallFunc_InCharacter_Void.generated.h"

/**
 * 
 */
UCLASS()
class SOULS_API UAN_CallFunc_InCharacter_Void : public UAN_Base_CallFunc_ByName
{
	GENERATED_BODY()
	
	UAN_CallFunc_InCharacter_Void();

	bool ProcessFunction(USkeletalMeshComponent* MeshComp) override;

};
