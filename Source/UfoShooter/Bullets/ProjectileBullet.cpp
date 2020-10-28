// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBullet.h"

AProjectileBullet::AProjectileBullet():Super()
{
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootMesh"));
	RootComponent = staticMesh;
	staticMesh->SetSimulatePhysics(true);
	staticMesh->SetEnableGravity(false);
	staticMesh->SetGenerateOverlapEvents(true);
	staticMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	
}

void AProjectileBullet::BeginPlay()
{
	Super::BeginPlay();
}


void AProjectileBullet::Fire()
{
	staticMesh->AddForce(2000.f*GetActorForwardVector()*10000.f);
}
