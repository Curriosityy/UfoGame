// Fill out your copyright notice in the Description page of Project Settings.


#include "AIShip.h"
#include "AiBehaviours\SinusoidMovement.h"
#include "AiBehaviours\MoveVectorProvider.h"
#include "ShipMovementComponent.h"
void AAIShip::BeginPlay()
{
	Super::BeginPlay();
	moveVectorProvider = new SinusoidMovement(3,3,0);
}

void AAIShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto moveVector = moveVectorProvider->GetMoveVector(DeltaTime);
	moveVector.X *= GetActorForwardVector().X;
	movementComponent->AddInputVector(moveVector);
}

void AAIShip::BeginDestroy()
{
	Super::BeginDestroy();
	//moveVectorProvider->~IMoveVectorProvider();
}