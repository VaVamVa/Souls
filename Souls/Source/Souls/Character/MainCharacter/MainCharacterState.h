// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"

class UAbilitySystemComponent;
class UAttributeSet;

#include "MainCharacterState.generated.h"

/**
 * 
 */
UCLASS()
class SOULS_API AMainCharacterState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = GAS, meta = (AllowPrivateAccess = true))
	TObjectPtr<UAbilitySystemComponent> ASComp;

	UPROPERTY(EditDefaultsOnly, Category = GAS, meta = (AllowPrivateAccess = true))
	TObjectPtr<UAttributeSet> AttributeSet;

public:
	AMainCharacterState();

	// IAbilitySystemInterface을(를) 통해 상속됨
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	FORCEINLINE UAttributeSet* GetAttributeSet() const { return AttributeSet; }

};
