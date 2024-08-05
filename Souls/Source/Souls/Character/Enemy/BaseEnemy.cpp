// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/BaseEnemy.h"

#include "Utilities/Helper.h"

#include "GAS/SoulsAbilitySystemComponent.h"
#include "GAS/SoulsAttributeSet.h"

ABaseEnemy::ABaseEnemy()
{
	ASComp = Helper::CreateActorComponent<USoulsAbilitySystemComponent>(this, "AbilitySystemComp");
	ASComp->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	ASComp->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<USoulsAttributeSet>("AttributeSet");
}

void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();

	ASComp->InitAbilityActorInfo(this, this);
}
