// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/BaseItem.h"

// Sets default values
ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseItem::SetID(FString InID)
{
	ID = InID;
	uint32 IntValue = FCString::Atoi(*InID.LeftChop(2));
	uint8 Category = static_cast<uint8>(IntValue);

	IntValue = FCString::Atoi(*InID.LeftChop(2));
	uint8 Group = static_cast<uint8>(IntValue);

	IntValue = FCString::Atoi(*InID);
	if (IntValue < 0 || IntValue > 255)
	{
		// ¿¹¿Ü
	}
	else
	{
		uint8 Number = static_cast<uint8>(IntValue);
	}
}

