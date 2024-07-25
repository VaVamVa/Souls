// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacter/MainCharacter.h"

#include "Utilities/Helper.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "Input/ControllerInputComp.h"

AMainCharacter::AMainCharacter()
{
	ControllerInputComp = Helper::CreateActorComponent<UControllerInputComp>(this, "IMC_Component");
	ControllerInputComp->SetOwner(this);
}

void AMainCharacter::BeginPlay()
{
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(Controller))
		ControllerInputComp->InitInputComponent(EnhancedInputComponent);
}

void AMainCharacter::Tick(float DeltaTime)
{
}
