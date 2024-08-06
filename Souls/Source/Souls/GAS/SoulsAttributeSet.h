// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"

#include "AbilitySystemComponent.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

#include "SoulsAttributeSet.generated.h"


/**
 * 
 */
UCLASS()
class SOULS_API USoulsAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	USoulsAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;


#pragma region Hp
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CurrentHealth, Category = "HP Attribute")
	FGameplayAttributeData CurHp;
	ATTRIBUTE_ACCESSORS(USoulsAttributeSet, CurHp)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "HP Attribute")
	FGameplayAttributeData MaxHp;

	UFUNCTION()
	void OnRep_CurrentHealth(const FGameplayAttributeData& OldCurHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
#pragma endregion Hp

#pragma region Mp
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CurrentMana, Category = "MP Attribute")
	FGameplayAttributeData CurMp;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "MP Attribute")
	FGameplayAttributeData MaxMp;

	UFUNCTION()
	void OnRep_CurrentMana(const FGameplayAttributeData& OldCurMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

#pragma endregion Mp

#pragma region Stemina
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CurrentStemina, Category = "Stemina Attribute")
	FGameplayAttributeData CurStemina;
	ATTRIBUTE_ACCESSORS(USoulsAttributeSet, CurStemina)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStemina, Category = "Stemina Attribute")
	FGameplayAttributeData MaxStemina;
	ATTRIBUTE_ACCESSORS(USoulsAttributeSet, MaxStemina)

	UFUNCTION()
	void OnRep_CurrentStemina(const FGameplayAttributeData& OldCurStemina) const;

	UFUNCTION()
	void OnRep_MaxStemina(const FGameplayAttributeData& OldMaxStemina) const;
#pragma endregion Stemina

#pragma region Status
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Status Attribute")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(USoulsAttributeSet, Strength)

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;


#pragma endregion Status

};
