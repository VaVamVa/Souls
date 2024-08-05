// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/MainCharacter/MainCharacter.h"

#include "Utilities/Helper.h"

#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "Input/ControllerInputComp.h"

#include "GAS/SoulsAbilitySystemComponent.h"
#include "GAS/SoulsAttributeSet.h"
#include "MainCharacterState.h"

AMainCharacter::AMainCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	GetMesh()->SetSkeletalMesh(Helper::GetAssetFromConstructor<USkeletalMesh>("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90.0));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	
	SpringArm = Helper::CreateSceneComponent<USpringArmComponent>(this, "SpringArm", GetCapsuleComponent());
	FollowCamera = Helper::CreateSceneComponent<UCameraComponent>(this, "Camera", SpringArm);

	ControllerInputComp = Helper::CreateActorComponent<UControllerInputComp>(this, "IMC_Component");
	ControllerInputComp->SetOwner(this);
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(Controller))
		ControllerInputComp->InitInputComponent(EnhancedInputComponent);
}

void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// For Server
	InitAbilityInfo();
}

void AMainCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// For Client
	InitAbilityInfo();
}

void AMainCharacter::InitAbilityInfo()
{
	AMainCharacterState* MainCharacterState = GetPlayerState<AMainCharacterState>();
	check(MainCharacterState);
	MainCharacterState->GetAbilitySystemComponent()->InitAbilityActorInfo(MainCharacterState, this);
	ASComp = MainCharacterState->GetAbilitySystemComponent();
	AttributeSet = MainCharacterState->GetAttributeSet();
}
