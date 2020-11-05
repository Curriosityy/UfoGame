// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ship.h"
#include "AIShip.generated.h"

/**
 * 
 */
class IMoveVectorProvider;
UCLASS()
class UFOSHOOTER_API AAIShip : public AShip
{
	GENERATED_BODY()
protected:
	IMoveVectorProvider* moveVectorProvider;
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginDestroy() override;
};
