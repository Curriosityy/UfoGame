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

	virtual void BeginPlay() override;

	UFUNCTION()
		void Die();

	UFUNCTION()
		virtual void MoveX(float value);
	UFUNCTION()
		virtual void MoveY(float value);


public:
	AShip();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPawnMovementComponent* GetMovementComponent() const;
	virtual void DealDamage(int damage);
};
