// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/BaseItem.h"
#include "BaseEquipment.generated.h"

/**
 * 
 */
UCLASS()
class SOULS_API ABaseEquipment : public ABaseItem
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	TObjectPtr<USkeletalMesh> SkeletalMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMesh> StaticMesh;

protected:
	UPROPERTY()
	bool bSkeletalMesh;
	
public:
	ABaseEquipment();

	USkeletalMesh* GetSkeletalMesh();

protected:

private:
};
