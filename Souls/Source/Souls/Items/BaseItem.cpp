// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/BaseItem.h"

#include "Utilities/Helper.h"

// Sets default values
ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;
	ID.Reserve(3);
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ABaseItem::SetID(FString InID)
{
	return SetID(FCString::Atoi(*InID));

	//uint32 IntValue = FCString::Atoi(*InID.LeftChop(2));
	//uint8 Category = static_cast<uint8>(IntValue);

	//IntValue = FCString::Atoi(*InID.LeftChop(2));
	//uint8 Group = static_cast<uint8>(IntValue);

	//IntValue = FCString::Atoi(*InID);
	//uint8 Number = 0;
	//if (IntValue < 0 || IntValue > 255)
	//{
	//	// ¿¹¿Ü
	//	return false;
	//}
	//else
	//{
	//	Number = static_cast<uint8>(IntValue);
	//}
}

bool ABaseItem::SetID(int32 InID)
{
	// Initialize ID Array
	if (ID.IsValidIndex(EID::Category))
		ID[EID::Category] = 0;
	else ID.Emplace(0);
	if (ID.IsValidIndex(EID::Group))
		ID[EID::Group] = 0;
	else ID.Emplace(0);
	if (ID.IsValidIndex(EID::Number))
		ID[EID::Number] = 0;
	else ID.Emplace(0);

	if (InID >= 10000000)
		return false;
	if (InID % 1000 < 0 || InID % 1000 > 255)
		return false;
	
	uint8 Number = static_cast<uint8>(InID % 1000);
	InID *= 0.001;
	uint8 Group = static_cast<uint8>(InID % 100);
	InID *= 0.01;
	uint8 Category = static_cast<uint8>(InID % 100);

	return SetID(Number, Group, Category);
}

bool ABaseItem::SetID(uint8 InNumber, uint8 InGroup, uint8 InCategory)
{
	if (InNumber == 0) return false;

	if (InCategory != 0) ID[EID::Category] = InCategory;
	if (InGroup != 0) ID[EID::Group] = InGroup;
	if (InNumber != 0) ID[EID::Number] = InNumber;
	
	return true;
}

void ABaseItem::SetMesh(USkeletalMesh* InSkeletalMesh)
{
	UStaticMeshComponent* DestructingComponent = GetComponentByClass< UStaticMeshComponent>();
	if (DestructingComponent)
	{
		DestructingComponent->Deactivate();
		DestructingComponent->DestroyComponent();
	}

	USkeletalMeshComponent* MeshComponent = GetComponentByClass<USkeletalMeshComponent>();
	if (!MeshComponent)
		Helper::CreateSceneComponent<USkeletalMeshComponent>(this, "Mesh", RootComponent);
	MeshComponent->SetSkeletalMesh(InSkeletalMesh);
}

void ABaseItem::SetMesh(UStaticMesh* InStaticMesh)
{
	USkeletalMeshComponent* DestructingComponent = GetComponentByClass<USkeletalMeshComponent>();
	if (DestructingComponent)
	{
		DestructingComponent->Deactivate();
		DestructingComponent->DestroyComponent();
	}

	UStaticMeshComponent* MeshComponent = GetComponentByClass<UStaticMeshComponent>();
	if (!MeshComponent)
		MeshComponent = Helper::CreateSceneComponent<UStaticMeshComponent>(this, "Mesh", RootComponent);
	MeshComponent->SetStaticMesh(InStaticMesh);
}

bool ABaseItem::GetMeshComponent(USkeletalMeshComponent*& OutSkeletalMeshComp) const
{
	USkeletalMeshComponent* Component = GetComponentByClass<USkeletalMeshComponent>();

	if (Component != nullptr)
	{
		OutSkeletalMeshComp = Component;
		return true;
	}

	return false;
}

bool ABaseItem::GetMeshComponent(UStaticMeshComponent*& OutStaticMeshComponent) const
{
	UStaticMeshComponent* Component = GetComponentByClass<UStaticMeshComponent>();

	if (Component != nullptr)
	{
		OutStaticMeshComponent = Component;
		return true;
	}

	return false;
}

const UMeshComponent* ABaseItem::GetMeshComponent() const
{
	UMeshComponent* Component = GetComponentByClass<USkeletalMeshComponent>();
	if (Component != nullptr)
		return Component;

	Component = GetComponentByClass<UStaticMeshComponent>();
	if (Component != nullptr)
		return Component;

	return nullptr;
}

