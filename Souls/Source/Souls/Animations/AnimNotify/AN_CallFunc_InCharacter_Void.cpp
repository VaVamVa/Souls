// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/AnimNotify/AN_CallFunc_InCharacter_Void.h"
#include "Character/BaseCharacter.h"


UAN_CallFunc_InCharacter_Void::UAN_CallFunc_InCharacter_Void()
{
	DefaultNotifyName = "Call Character's Function";
}

bool UAN_CallFunc_InCharacter_Void::ProcessFunction(USkeletalMeshComponent* MeshComp)
{
	if (MeshComp->GetOwner()->StaticClass() != ABaseCharacter::StaticClass()) return false;
	
	ABaseCharacter* Character = Cast<ABaseCharacter>(MeshComp->GetOwner());
	UFunction* function = Character->FindFunction(FName(FunctionName));

	if (!function->IsValidLowLevelFast()) return false;
	
	Character->ProcessEvent(function, nullptr);

	return true;
}
