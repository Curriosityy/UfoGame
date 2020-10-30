// Fill out your copyright notice in the Description page of Project Settings.


#include "GunShip.h"
#include <UfoShooter\Guns\Gun.h>
AGunShip::AGunShip() 
{
	muzzlePosition = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzlePosition"));
	muzzlePosition->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
}

void AGunShip::BeginPlay()
{
	Super::BeginPlay();
	SwitchGun(GetWorld()->SpawnActor<AGun>(startGunBP));
}

void AGunShip::Shoot()
{
	currentGun->FireProjectile();
}

void AGunShip::SwitchGun(AGun* newGun)
{
	currentGun = newGun;
	currentGun->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	currentGun->SetActorTransform(muzzlePosition->GetComponentTransform());
	newGun->SetOwner(this);
}

AGun* AGunShip::GetCurrentGun() const
{
	return currentGun;
}