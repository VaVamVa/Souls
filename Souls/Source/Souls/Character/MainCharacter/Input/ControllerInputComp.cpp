// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacter/Input/ControllerInputComp.h"

#include "Character/MainCharacter/MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"


// Sets default values for this component's properties
UControllerInputComp::UControllerInputComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UControllerInputComp::SetOwner(AMainCharacter* InOwner)
{
	OwnerCharacter = InOwner;
	Controller = Cast<APlayerController>(InOwner->Controller);
}

void UControllerInputComp::InitInputComponent(UEnhancedInputComponent* EnhancedInputComponent)
{
	IMC_Default();
	IMC_Combat();
	IMC_Game_Interaction();
	IMC_UI_Interaction();
}


// Called when the game starts
void UControllerInputComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//OwnerCharacter->AddMovementInput();
}


// Called every frame
void UControllerInputComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UControllerInputComp::IMC_Default()
{
	//DefaultMappingContext->;
	//UInputAction* Action = ;

	return true;
}

bool UControllerInputComp::IMC_Combat()
{
	
	return true;
}

bool UControllerInputComp::IMC_Game_Interaction()
{
	return true;
}

bool UControllerInputComp::IMC_UI_Interaction()
{
	return true;
}

