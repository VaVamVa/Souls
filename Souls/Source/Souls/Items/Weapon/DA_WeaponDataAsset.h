// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_WeaponDataAsset.generated.h"

class ABaseWeapon;
class ABaseCharacter;

USTRUCT()
struct FActionMontage
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TObjectPtr<UAnimMontage> Montage;

	UPROPERTY()
	float Damage;

	UPROPERTY()
	float PlayRate;
};

/**
 * 
 */
UCLASS()
class SOULS_API UDA_WeaponDataAsset : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = Class, meta = (AllowPrivateAccess = true))
	TSubclassOf<ABaseWeapon> WeaponClass;

	UPROPERTY(EditDefaultsOnly, Category=HandleSocket, meta=(AllowPrivateAccess=true))
	FName RightHandleSocketName;
	
	UPROPERTY(EditDefaultsOnly, Category = HandleSocket, meta = (AllowPrivateAccess = true))
	FName LeftHandleSocketName;


};
