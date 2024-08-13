// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "FItemTypes_Manual.h"


#include "BaseItem.generated.h"

UCLASS()
class SOULS_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category = Datas, meta = (AllowPrivateAccess = true))
	TArray<uint8> ID;  // Category-Group-Number

public:	
	ABaseItem();

protected:
	virtual void BeginPlay() override;

protected:

public:	
#pragma region Setter
	bool SetID(FString InID);
	bool SetID(int32 InID);
	bool SetID(uint8 Category, uint8 Group, uint8 Number);

	void SetMesh(USkeletalMesh* InSkeletalMesh);
	void SetMesh(UStaticMesh* InStaticMesh);


#pragma endregion Setter


#pragma region Getter
	FORCEINLINE TArray<uint8> GetID() { return ID; }

	bool GetMeshComponent(USkeletalMeshComponent* &OutSkeletalMeshComp) const;
	bool GetMeshComponent(UStaticMeshComponent* &OutStaticMeshComp) const;
	UFUNCTION(BlueprintCallable, Category = "Getter")
	const UMeshComponent* GetMeshComponent() const;

#pragma endregion Getter


};
