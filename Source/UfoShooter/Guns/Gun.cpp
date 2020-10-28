// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include <UfoShooter\Bullets\Bullet.h>
// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

float AGun::GetFirerate() const
{
	return fireRate;
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	world = GetWorld();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::FireProjectile()
{
	FActorSpawnParameters pars;
	pars.Owner = GetOwner();
	auto bullet = world->SpawnActor<ABullet>(bulletBP, pars);
	bullet->SetActorTransform(GetActorTransform());
	bullet->Fire();
}

