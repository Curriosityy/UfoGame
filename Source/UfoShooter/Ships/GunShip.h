// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ship.h"
#include "GunShip.generated.h"

/**
 * 
 */
class AGun;
UCLASS()
class UFOSHOOTER_API AGunShip : public AShip
{
	GENERATED_BODY()
public:
	AGunShip();
protected:
	UPROPERTY(EditAnywhere)
		TSubclassOf<AGun> startGunBP;
	UPROPERTY(EditAnywhere)
		USceneComponent* muzzlePosition;

	AGun* currentGun;

	UFUNCTION()
		virtual void SwitchGun(AGun* newGun);
	UFUNCTION()
		virtual void Shoot();
public:
	AGun* GetCurrentGun() const;
	virtual void BeginPlay() override;

};
