#include "ActorComponents/EquipmentComponent.h"
#include "SkeletalMeshMerge.h"

#include "Items/Equipment/BaseEquipment.h"
#include "Items/Weapon/BaseWeapon.h"
#include "Character/BaseCharacter.h"


#include "Utilities/Debug.h"


UEquipmentComponent::UEquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ABaseCharacter>(GetOwner());
	
}

void UEquipmentComponent::EquipWeapon()
{

}

