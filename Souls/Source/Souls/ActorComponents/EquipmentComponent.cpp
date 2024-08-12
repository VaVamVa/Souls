#include "ActorComponents/EquipmentComponent.h"
#include "SkeletalMeshMerge.h"

#include "Items/Equipment/BaseEquipment.h"

UEquipmentComponent::UEquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();


}

