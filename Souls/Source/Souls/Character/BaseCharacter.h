// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "BaseCharacter.generated.h"

UCLASS()
class SOULS_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = AnimationValue, meta=(AllowPrivateAccess=true))
	bool bMirror;

	UPROPERTY(EditDefaultsOnly, Category=AnimationValue, meta=(AllowPrivateAccess=true))
	bool bAiming;

public:
	ABaseCharacter();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:

#pragma region Getter
	FORCEINLINE bool IsAiming() { return bAiming; }

#pragma endregion Getter


#pragma region Setter
	FORCEINLINE void SetMirror(bool InValue) { bMirror = InValue; }

#pragma endregion Setter


};
