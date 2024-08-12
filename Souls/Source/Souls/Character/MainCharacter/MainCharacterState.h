// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"

class UAbilitySystemComponent;
class USoulsAttributeSet;
struct FOnAttributeChangeData;

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
	TObjectPtr<USoulsAttributeSet> AttributeSet;

public:
	AMainCharacterState();

	// IAbilitySystemInterface을(를) 통해 상속됨
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	FORCEINLINE USoulsAttributeSet* GetAttributeSet() const { return AttributeSet; }

	virtual void ChangeHealth(const FOnAttributeChangeData& Data);

};
