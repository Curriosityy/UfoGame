// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GunShip.h"
#include "AutoAttackShip.generated.h"

/**
 * 
 */
UCLASS()
class UFOSHOOTER_API AAutoAttackShip : public AGunShip
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
protected:
	UFUNCTION()
		void StartShooting();
	UFUNCTION()
		void StopShooting();

	FTimerHandle timeHandler;

	virtual void SwitchGun(AGun* newGun) override;
};
