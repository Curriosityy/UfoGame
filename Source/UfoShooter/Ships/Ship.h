// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <UfoShooter\Damageable.h>
#include "Ship.generated.h"
class UShipMovementComponent;
class AGun;
UCLASS()
class UFOSHOOTER_API AShip : public APawn, public IDamageable
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		int maxHP;
protected:
	int hp;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* meshComponent;
	UPROPERTY(EditAnywhere)
		UShipMovementComponent* movementComponent;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AGun> startGunBP;
	UPROPERTY(EditAnywhere)
		USceneComponent* muzzlePosition;

	AGun* currentGun;
	FTimerHandle timeHandler;
	virtual void BeginPlay() override;

	virtual void MoveX(float value);
	virtual void MoveY(float value);
	UFUNCTION()
	virtual void Shoot();

	UFUNCTION()
	void StartShooting();
	UFUNCTION()
	void SwitchGun(AGun* newGun);
	UFUNCTION()
	void StopShooting();
	UFUNCTION()
	void Die();
public:
	AShip();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPawnMovementComponent* GetMovementComponent() const;
	AGun* GetCurrentGun() const;
	virtual void DealDamage(int damage);
};
