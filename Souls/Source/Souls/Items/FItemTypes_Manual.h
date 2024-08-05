#pragma once

#include "CoreMinimal.h"

#include "EItemTypes_Manual.h"

#include "FItemTypes_Manual.generated.h"

// Item Row, O0 O0 000 : ItemCategory, Item Group, Item ID

USTRUCT(Blueprintable)
struct FItemTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, meta = (DisplayName = "Item Name"))
	FString Name;

	UPROPERTY(EditDefaultsOnly, meta = (DisplayName = "Item Category"))
	uint8 Category;

	UPROPERTY(EditDefaultsOnly, meta = (DisplayName = "Item Group"))
	uint8 Group;

	UPROPERTY(EditDefaultsOnly, meta = (DisplayName = "Item Number"))
	uint8 Number;

};