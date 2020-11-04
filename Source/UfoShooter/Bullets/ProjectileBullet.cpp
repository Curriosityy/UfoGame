// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBullet.h"
#include "GameFramework/ProjectileMovementComponent.h"

AProjectileBullet::AProjectileBullet()
{
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootMesh"));
	RootComponent = staticMesh;
	staticMesh->SetSimulatePhysics(true);
	staticMesh->SetEnableGravity(false);
	staticMesh->SetGenerateOverlapEvents(true);
	staticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
	movement=CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	movement->Bounciness = 1.f;
	movement->bShouldBounce = false;
	movement->ProjectileGravityScale = 0.0f;
	movement->Friction = 0;
	movement->Velocity = FVector(0, 0, 0);
	movement->bSnapToPlaneAtStart = true;
	movement->bConstrainToPlane = true;
	movement->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Z);

}

void AProjectileBullet::BeginPlay()
{
	Super::BeginPlay();
}


void AProjectileBullet::Fire()
{
	auto forceToAdd = 5000.f * GetActorForwardVector();
	//forceToAdd *= 1000.f;
	movement->Velocity = forceToAdd;
	//movement->AddForce(forceToAdd);

}
