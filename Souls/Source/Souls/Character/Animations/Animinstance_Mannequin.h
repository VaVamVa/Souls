// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"

class ABaseCharacter;

#include "Animinstance_Mannequin.generated.h"

/**
 * 
 */
UCLASS()
class SOULS_API UAniminstance_Mannequin : public UAnimInstance
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Character", meta = (AllowPrivateAccess = true))
	ABaseCharacter* OwnerCharacter;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "BlendSpace", meta = (AllowPrivateAccess = true))
	float Speed;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "BlendSpace", meta = (AllowPrivateAccess = true))
	float Direction;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "BlendSpace", meta = (AllowPrivateAccess = true, ClampMin = 0.00))
	bool bFalling;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "BlendSpace", meta = (AllowPrivateAccess = true, ClampMin = 0.00))
	bool bAiming;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "BlendSpace", meta = (AllowPrivateAccess = true, ClampMin = 0.00))
	float Yaw;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "BlendSpace", meta = (AllowPrivateAccess = true, ClampMin = 0.00))
	float Pitch;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Mirror", meta = (AllowPrivateAccess = true, ClampMin = 0.00))
	bool bMirror;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "IK", meta = (AllowPrivateAccess = true, ClampMin = 0.00))
	FVector AdditionalLHGripLocation;  // by weapon socket name

public:
	void NativeInitializeAnimation() override;
	void NativeUpdateAnimation(float DeltaSecond) override;

	FORCEINLINE void SetAdditionalGripLocation(FVector InLocation) { AdditionalLHGripLocation = InLocation; }

private:
	void UpdateBlendSpaceValues();

	
};
