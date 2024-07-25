// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/AnimNotify/AN_Base_CallFunc_ByName.h"

DEFINE_LOG_CATEGORY(CallFuncByNameLog)

FString UAN_Base_CallFunc_ByName::GetNotifyName_Implementation() const
{
	if (FunctionName != "None" || FunctionName != "")
		return "Call " + FunctionName;

	return DefaultNotifyName;
}

void UAN_Base_CallFunc_ByName::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventRef)
{
	Super::Notify(MeshComp, Animation, EventRef);

	if (ProcessFunction(MeshComp)) return;

	FString LogText = "Cant Find " + FunctionName + ". Check Notify Function Name";
	UE_LOG(CallFuncByNameLog, Warning, TEXT("%s"), *LogText);
}
