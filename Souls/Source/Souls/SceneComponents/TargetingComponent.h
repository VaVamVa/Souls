// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

class ABaseCharacter;

#include "TargetingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOULS_API UTargetingComponent : public USceneComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = TargetPoint, meta = (AllowPrivateAccess = true))
	TArray<FVector> TargetPoints;

public:	
	UTargetingComponent();
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	void CreateTargetPoints(int InPointsCount);

	bool GetClosestPoint(FVector InLocation, float& OutClosestDistance, FVector& OutTargetPoint);
	bool GetClosestPoint(ABaseCharacter* InTargetActor, float& OutClosestDistance, FVector& OutTargetPoint);
		
};
