#pragma once

#include "CoreMinimal.h"


//// Item Category

UENUM(Blueprintable)
enum class EItemCategory : uint8
{
	Cat00_None				UMETA(Hidden, DisplayName="None"),
	Cat01_Consumable		UMETA(DisplayName="Consumable"),
	Cat02_Projectile		UMETA(DisplayName="Arrow"),
	Cat03_Weapon			UMETA(DisplayName="Weapon"),
	Cat04_Equipment			UMETA(DisplayName = "Equipment"),
	Cat05_Cast				UMETA(DisplayName="Cast"),
	Cat06_Accessary			UMETA(DisplayName = "Accessary"),
	Cat07_Etc				UMETA(DisplayName = "Etc")
};


//// Item Group 

UENUM(Blueprintable)
enum class EConsumable : uint8
{
	G00_None				UMETA(Hidden, DisplayName = "None"),
	G01_Potion				UMETA(DisplayNAme="HP Potion"),
	G02_BuffItem			UMETA(DisplayNAme="Buff Item"),
	G03_Bomb				UMETA(DisplayNAme="Bomb")
};

UENUM(Blueprintable)
enum class EProjectile : uint8
{
	G00_None				UMETA(Hidden, DisplayName = "None"),
	G01_Arrow				UMETA(DisplayNAme="Arrow"),
	G02_Bolt				UMETA(DisplayName="Bolt")

};

UENUM(Blueprintable)
enum class EWeapon : uint8
{
	G00_None				UMETA(Hidden, DisplayName = "None"),
	G01_Sword				UMETA(DisplayName = "Sword"),
	G02_GreatSword			UMETA(DisplayName = "GreatSword"),
	G03_Fist				UMETA(DisplayName = "Fist"),
	G04_Shield				UMETA(DisplayName = "Shield"),
	G05_Staff				UMETA(DisplayName = "Staff"),
	G06_Halidom				UMETA(DisplayName = "Halidom")
};

UENUM(Blueprintable)
enum class EEquipment : uint8
{
	G00_None				UMETA(Hidden, DisplayName = "None"),
	G01_Head				UMETA(DisplayName = "Head"),
	G02_Chest				UMETA(DisplayName = "Chest"),
	G03_Hand				UMETA(DisplayName = "Hand"),
	G04_Lag					UMETA(DisplayName = "Lag"),
};

UENUM(Blueprintable)
enum class ECast : uint8
{
	G00_None				UMETA(Hidden, DisplayName = "None"),
	G01_Magic				UMETA(DisplayName="Magic"),
	G02_Holy				UMETA(DisplayName="Holy")

};

UENUM(Blueprintable)
enum class EAccessary : uint8
{
	G00_None				UMETA(Hidden, DisplayName = "None"),
	G01_Ring				UMETA(DisplayName = "Ring")
};

UENUM(Blueprintable)
enum class EEtc : uint8
{
	G00_None				UMETA(Hidden, DisplayName = "None"),
	G01_Enhancer			UMETA(DisplayName = "Enhancer"),
	G02_Stuff				UMETA(DisplayName = "Stuff")

};