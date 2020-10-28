// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include <UfoShooter\Damageable.h>
// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add("Bullet");

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ABullet::BulletHit);
}



// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABullet::BulletHit(AActor* OverlappedActor, AActor* OtherActor)
{
	if (GetOwner() == OtherActor)
	{
		return;
	}
	auto damageable = Cast<IDamageable>(OtherActor);
	if(damageable)
	{
		damageable->DealDamage(damage);
	}
}

void ABullet::Fire()
{
	check(0 && "Fire need to be overrided");
}


