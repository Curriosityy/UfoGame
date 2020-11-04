// Fill out your copyright notice in the Description page of Project Settings.


#include "AIShip.h"
#include "AiBehaviours\SinusoidMovement.h"
#include "ShipMovementComponent.h"
void AAIShip::BeginPlay()
{
	Super::BeginPlay();
	moveVectorProvider = new SinusoidMovement();
}

void AAIShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto moveVector = moveVectorProvider->GetMoveVector(DeltaTime);
	moveVector.X *= GetActorForwardVector().X;
	movementComponent->AddInputVector(moveVector);
}
