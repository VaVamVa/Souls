// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ControllerInputComp.generated.h"

class AMainCharacter;
class UEnhancedInputComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOULS_API UControllerInputComp : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<AMainCharacter> OwnerCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category=Controller, meta=(AllowPrivateAccess=true))
	TObjectPtr<APlayerController> Controller;

	#pragma region Default Move & View
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GameMode, meta=(AllowPrivateAccess=true))
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = Default, meta=(AllowPrivateAccess=true))
	TObjectPtr<UInputAction> Move;

	UPROPERTY(EditDefaultsOnly, Category = Default, meta=(AllowPrivateAccess=true))
	TObjectPtr<UInputAction> View;
	#pragma endregion

	#pragma region Combat
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GameMode, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputMappingContext> CombatMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = Default, meta=(AllowPrivateAccess=true))
	TObjectPtr<UInputAction> MouseLeft;

	UPROPERTY(EditDefaultsOnly, Category = Default, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> MouseRight;

	UPROPERTY(EditDefaultsOnly, Category = Default, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> Heavy;

	UPROPERTY(EditDefaultsOnly, Category = Default, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInputAction> Special;
	#pragma endregion

public:	
	// Sets default values for this component's properties
	UControllerInputComp();

	void SetOwner(AMainCharacter* InOwner);

	void InitInputComponent(UEnhancedInputComponent* EnhancedInputComponent);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:  // Make Mapping Contexts
	bool IMC_Default();
	bool IMC_Combat();
	bool IMC_Game_Interaction();
	bool IMC_UI_Interaction();


	

private:


};
