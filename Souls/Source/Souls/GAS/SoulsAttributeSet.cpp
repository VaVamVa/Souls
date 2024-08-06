// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/SoulsAttributeSet.h"

#include "Net/UnrealNetwork.h"

USoulsAttributeSet::USoulsAttributeSet()
{
}

void USoulsAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(USoulsAttributeSet, CurHp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USoulsAttributeSet, MaxHp, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(USoulsAttributeSet, CurMp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(USoulsAttributeSet, MaxMp, COND_None, REPNOTIFY_Always);

}

void USoulsAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& OldCurHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USoulsAttributeSet, CurHp, OldCurHealth);
}

void USoulsAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USoulsAttributeSet, MaxHp, OldMaxHealth);
}

void USoulsAttributeSet::OnRep_CurrentMana(const FGameplayAttributeData& OldCurMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USoulsAttributeSet, CurMp, OldCurMana);
}

void USoulsAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USoulsAttributeSet, MaxMp, OldMaxMana);
}

void USoulsAttributeSet::OnRep_CurrentStemina(const FGameplayAttributeData& OldCurStemina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USoulsAttributeSet, CurStemina, OldCurStemina);
}

void USoulsAttributeSet::OnRep_MaxStemina(const FGameplayAttributeData& OldMaxStemina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USoulsAttributeSet, MaxStemina, OldMaxStemina);
}

void USoulsAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USoulsAttributeSet, Strength, OldStrength);
}