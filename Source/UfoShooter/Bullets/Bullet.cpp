// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include <UfoShooter\IDamageable.h>
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
	OnActorHit.AddDynamic(this, &ABullet::BulletHit);
}



// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::BulletHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->GetClass()->IsChildOf(IDamageable::StaticClass()))
	{
		((IDamageable*)OtherActor)->DealDamage(damage);
	}
}

