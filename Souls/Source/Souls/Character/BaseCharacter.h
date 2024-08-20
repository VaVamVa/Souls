// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"

class UAbilitySystemComponent;
class UAttributeSet;
class ABaseWeapon;

#include "BaseCharacter.generated.h"

USTRUCT(Blueprintable)
struct FAnimMontageArray
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly)
	TArray<UAnimMontage*> Montages;
};

UCLASS(Abstract)
class SOULS_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = AnimationValue, meta=(AllowPrivateAccess=true))
	bool bMirror;

	UPROPERTY(EditDefaultsOnly, Category=AnimationValue, meta=(AllowPrivateAccess=true))
	bool bAiming;

protected:
	UPROPERTY(EditDefaultsOnly, Category=GAS, meta=(AllowPrivateAccess=true))
	TObjectPtr<UAbilitySystemComponent> ASComp;
	
	UPROPERTY(EditDefaultsOnly, Category=GAS, meta=(AllowPrivateAccess=true))
	TObjectPtr<UAttributeSet> AttributeSet;

public:
	ABaseCharacter();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:
#pragma region Getter
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;


	FORCEINLINE UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	FORCEINLINE bool IsAiming() const { return bAiming; }

#pragma endregion Getter


#pragma region Setter
	FORCEINLINE void SetMirror(bool InValue) { bMirror = InValue; }

#pragma endregion Setter


};
