// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"

DECLARE_LOG_CATEGORY_EXTERN(CallFuncByNameLog, Log, All)

#include "AN_Base_CallFunc_ByName.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class SOULS_API UAN_Base_CallFunc_ByName : public UAnimNotify
{
	GENERATED_BODY()
	
	FString GetNotifyName_Implementation() const;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventRef) override;

protected:
	UPROPERTY(EditInstanceOnly)
	FString FunctionName = "None";

	FString DefaultNotifyName = "PURE Notify Class";

	virtual bool ProcessFunction(USkeletalMeshComponent* MeshComp)
	PURE_VIRTUAL(UAN_Base_CallFunc_ByName::ProcessFunction, return false;);

};
