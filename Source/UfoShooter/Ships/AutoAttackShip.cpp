// Fill out your copyright notice in the Description page of Project Settings.


#include "AutoAttackShip.h"
#include <UfoShooter\Guns\Gun.h>
void AAutoAttackShip::BeginPlay()
{
	Super::BeginPlay();
}

void AAutoAttackShip::StartShooting()
{
	GetWorldTimerManager().SetTimer(timeHandler, this, &AAutoAttackShip::Shoot, currentGun->GetFirerate(), true, 0.f);
}

void AAutoAttackShip::StopShooting()
{
	GetWorldTimerManager().ClearTimer(timeHandler);
}

void AAutoAttackShip::SwitchGun(AGun* newGun) 
{
	StopShooting();
	Super::SwitchGun(newGun);
	StartShooting();
}