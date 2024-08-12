// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//https://dev.epicgames.com/documentation/en-us/unreal-engine/modular-characters-in-unreal-engine

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

class ABaseEquipment;

#include "EquipmentComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOULS_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEquipmentComponent();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	TObjectPtr<ABaseEquipment> Head;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<ABaseEquipment> Chest;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<ABaseEquipment> Hand;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<ABaseEquipment> Leg;

protected:
	virtual void BeginPlay() override;

public:	
	
		
};
