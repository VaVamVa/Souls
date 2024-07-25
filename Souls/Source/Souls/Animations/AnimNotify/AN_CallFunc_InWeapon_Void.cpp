// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/AnimNotify/AN_CallFunc_InWeapon_Void.h"
#include "Character/BaseCharacter.h"
#include "Items/Weapon/BaseWeapon.h"

UAN_CallFunc_InWeapon_Void::UAN_CallFunc_InWeapon_Void()
{
	DefaultNotifyName = "Call Weapon's Function";
}

bool UAN_CallFunc_InWeapon_Void::ProcessFunction(USkeletalMeshComponent* MeshComp)
{
	ABaseWeapon* Weapon = nullptr;

	if (MeshComp->GetOwner()->StaticClass() == ABaseWeapon::StaticClass())
	{
		Weapon = Cast<ABaseWeapon>(MeshComp->GetOwner());

	}
	else if (MeshComp->GetOwner()->StaticClass() == ABaseCharacter::StaticClass())
	{
		ABaseCharacter* Character = Cast<ABaseCharacter>(MeshComp->GetOwner());
		// Chracter -> Weapon Component -> Equipped Weapon
	}
	else return false;
		
	UFunction* function = Weapon->FindFunction(FName(FunctionName));
	
	if (!function->IsValidLowLevelFast()) return false;
	
	Weapon->ProcessEvent(function, nullptr);
	
	return true;
}
