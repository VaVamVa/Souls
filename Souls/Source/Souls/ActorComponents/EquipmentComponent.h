// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//https://dev.epicgames.com/documentation/en-us/unreal-engine/modular-characters-in-unreal-engine

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"



class ABaseEquipment;
class ABaseWeapon;

#include "EquipmentComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOULS_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEquipmentComponent();

	UPROPERTY(EditDefaultsOnly, Category = Owner)
	TObjectPtr<class ABaseCharacter> OwnerCharacter;

	UPROPERTY(EditDefaultsOnly, Category = Equipment, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	TObjectPtr<ABaseEquipment> Head;

	UPROPERTY(EditDefaultsOnly, Category = Equipment, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<ABaseEquipment> Chest;

	UPROPERTY(EditDefaultsOnly, Category = Equipment, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<ABaseEquipment> Hand;

	UPROPERTY(EditDefaultsOnly, Category = Equipment, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	TObjectPtr<ABaseEquipment> Leg;

	UPROPERTY(EditDefaultsOnly, Category = Weapon, meta = (AllowPrivateAccess = true))
	TObjectPtr<ABaseWeapon> EquippedWeaponRight;

	UPROPERTY(EditDefaultsOnly, Category = Weapon, meta = (AllowPrivateAccess = true))
	TObjectPtr<ABaseWeapon> EquippedWeaponLeft;

protected:
	virtual void BeginPlay() override;

public:	
	void EquipWeapon();

#pragma region Getter
	FORCEINLINE ABaseWeapon* GetEquippedWeaponRight() const { return EquippedWeaponRight; }
	FORCEINLINE ABaseWeapon* GetEquippedWeaponLeft() const { return EquippedWeaponLeft; }

#pragma endregion Getter
		
};
