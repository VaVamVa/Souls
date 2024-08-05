// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/PlayerHUD.h"

#include "Character/MainCharacter/MainCharacter.h"
#include "Kismet/GameplayStatics.h"

APlayerHUD::APlayerHUD()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	MainCharacter = Cast<AMainCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
}

void APlayerHUD::Tick(float Delta)
{
	Super::Tick(Delta);
}
