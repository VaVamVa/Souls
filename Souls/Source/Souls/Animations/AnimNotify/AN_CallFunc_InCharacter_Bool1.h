// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animations/AnimNotify/AN_Base_CallFunc_ByName.h"
#include "AN_CallFunc_InCharacter_Bool1.generated.h"

/**
 * 
 */
UCLASS()
class SOULS_API UAN_CallFunc_InCharacter_Bool1 : public UAN_Base_CallFunc_ByName
{
	GENERATED_BODY()

	UAN_CallFunc_InCharacter_Bool1();

	UPROPERTY(EditInstanceOnly, meta=(AllowPrivateAccess=true))
	bool Param = false;

	bool ProcessFunction(USkeletalMeshComponent* MeshComp) override;
};
