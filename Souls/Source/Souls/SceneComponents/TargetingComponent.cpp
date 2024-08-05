// Fill out your copyright notice in the Description page of Project Settings.


#include "SceneComponents/TargetingComponent.h"

#include "Character/BaseCharacter.h"
#include <limits>


UTargetingComponent::UTargetingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTargetingComponent::BeginPlay()
{
	Super::BeginPlay();

	FVector MiddleTargetPoint = Cast<ABaseCharacter>(GetOwner())->GetMesh()->GetSocketLocation("Target_Point_0");
	TargetPoints.Add(MiddleTargetPoint);
}

void UTargetingComponent::CreateTargetPoints(int InPointsCount)
{
	ABaseCharacter* OwnerCharacter = Cast<ABaseCharacter>(GetOwner());
	for (int i = 1; i <= InPointsCount; i++)
	{
		FName SocketName = FName("Target_Point_" + FString::FromInt(i));
		if (OwnerCharacter->GetMesh()->DoesSocketExist(SocketName))
			TargetPoints.Add(OwnerCharacter->GetMesh()->GetSocketLocation(SocketName));
	}
}

bool UTargetingComponent::GetClosestPoint(FVector InLocation, float& OutClosestDistance, FVector& OutTargetPoint)
{
	OutClosestDistance = TNumericLimits<float>::Max();
	bool flag = false;

	for (const FVector Point : TargetPoints)
	{
		float Distance = FVector::Dist(Point, InLocation);
		if (OutClosestDistance > Distance)
		{
			OutClosestDistance = Distance;
			OutTargetPoint = Point;
			flag = true;
		}
	}

	return flag;
}

bool UTargetingComponent::GetClosestPoint(ABaseCharacter* InTargetActor, float& OutClosestDistance, FVector& OutTargetPoint)
{
	OutClosestDistance = TNumericLimits<float>::Max();
	bool flag = false;

	return flag;
}


// Called every frame
//void UTargetingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

