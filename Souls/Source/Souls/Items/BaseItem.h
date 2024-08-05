// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "FItemTypes_Manual.h"

class StaticMeshComponent;

#include "BaseItem.generated.h"

UCLASS()
class SOULS_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category = Datas, meta = (AllowPrivateAccess = true))
	FString ID;  // 00-00-000

	UPROPERTY(EditDefaultsOnly, Category = Mesh, meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> Mesh;

public:	
	ABaseItem();

protected:
	virtual void BeginPlay() override;

protected:
	void SetID(FString InID);

public:	

#pragma region Getter
	FORCEINLINE FString GetID() { return ID; }

#pragma endregion Getter


#pragma region Setter

#pragma endregion Setter
};
