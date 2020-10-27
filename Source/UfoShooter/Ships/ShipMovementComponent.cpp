// Fill out your copyright notice in the Description page of Project Settings.

#include "ShipMovementComponent.h"

UShipMovementComponent::UShipMovementComponent()
{
	SetPlaneConstraintEnabled(true);
	SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::Z);
}

void UShipMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{
		return;
	}
	auto inputVector = ConsumeInputVector();
	FVector DesiredMovementThisFrame = inputVector.GetClampedToMaxSize(1.0f) * DeltaTime * 1000.f * (3.0f);
	
	if (!DesiredMovementThisFrame.IsNearlyZero())
	{
		UE_LOG(LogTemp, Warning, TEXT("Move %f %f %f"), DesiredMovementThisFrame.X, DesiredMovementThisFrame.Y, DesiredMovementThisFrame.Z);
		FHitResult Hit;
		SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);
	}
}