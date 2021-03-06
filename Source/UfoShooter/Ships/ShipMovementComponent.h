// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "ShipMovementComponent.generated.h"
/**
 * 
 */
UCLASS()
class UFOSHOOTER_API UShipMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
public:
	UShipMovementComponent();
private:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
