// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMovementComponent.h"
#include "AiBehaviours\MoveVectorProvider.h"
#include "ShipMovementComponent.h"
// Sets default values for this component's properties
UAIMovementComponent::UAIMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


void UAIMovementComponent::Initialize(IMoveVectorProvider* movementComponent)
{
	if (moveVectorProvider)
		moveVectorProvider->~IMoveVectorProvider();
	moveVectorProvider = movementComponent;
}

IMoveVectorProvider* UAIMovementComponent::GetMovementVectorProvider() const
{
	return moveVectorProvider;
}

// Called when the game starts
void UAIMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	owner = GetOwner();
	shipMovementComponent = owner->FindComponentByClass<UShipMovementComponent>();
}


// Called every frame
void UAIMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (moveVectorProvider)
	{
		auto moveVector = moveVectorProvider->GetMoveVector(DeltaTime);
		moveVector.X *= owner->GetActorForwardVector().X;
		shipMovementComponent->AddInputVector(moveVector);
	}
}

