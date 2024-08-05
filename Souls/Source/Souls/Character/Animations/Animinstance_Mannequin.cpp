// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Animations/Animinstance_Mannequin.h"

#include "Character/BaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "KismetAnimationLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet2/BlueprintEditorUtils.h"

#include "Animation/AnimLayerInterface.h"

void UAniminstance_Mannequin::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwnerCharacter = Cast<ABaseCharacter>(TryGetPawnOwner());
}

void UAniminstance_Mannequin::NativeUpdateAnimation(float DeltaSecond)
{
	Super::NativeUpdateAnimation(DeltaSecond);

	if (!OwnerCharacter->IsValidLowLevelFast()) return;

	UpdateBlendSpaceValues();

	if (!IsAnyMontagePlaying()) 
	{
		bMirror = false;
		OwnerCharacter->SetMirror(bMirror);
	}
}

void UAniminstance_Mannequin::UpdateBlendSpaceValues()
{
	UCharacterMovementComponent* MovementComponent = OwnerCharacter->GetCharacterMovement();

	if (MovementComponent == nullptr) return;

	bFalling = MovementComponent->IsFalling();
	bAiming = OwnerCharacter->IsAiming();

	FVector Velocity = OwnerCharacter->GetVelocity();
	Speed = Velocity.Size2D();

	FRotator Rotation = OwnerCharacter->GetControlRotation();
	Direction = UKismetAnimationLibrary::CalculateDirection(Velocity, Rotation);

	FRotator AimingRotation = UKismetMathLibrary::NormalizedDeltaRotator(Rotation, OwnerCharacter->GetActorRotation());
	Yaw = AimingRotation.Yaw;
	Pitch = AimingRotation.Pitch;

	
}
