// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacter/MainCharacterState.h"

#include "Utilities/Helper.h"

#include "GAS/SoulsAbilitySystemComponent.h"
#include "GAS/SoulsAttributeSet.h"

AMainCharacterState::AMainCharacterState()
{
	NetUpdateFrequency = 10.0f;

	ASComp = Helper::CreateActorComponent<USoulsAbilitySystemComponent>(this, "AbilitySystemComp");
	ASComp->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	ASComp->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<USoulsAttributeSet>("AttributeSet");

	ASComp->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetCurHpAttribute()).AddUObject(this, &AMainCharacterState::ChangeHealth);

}

UAbilitySystemComponent* AMainCharacterState::GetAbilitySystemComponent() const
{
	return ASComp;
}

void AMainCharacterState::ChangeHealth(const FOnAttributeChangeData& Data)
{
}
