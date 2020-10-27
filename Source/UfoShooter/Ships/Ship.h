// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ship.generated.h"
class UShipMovementComponent;
UCLASS()
class UFOSHOOTER_API AShip : public APawn
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
	void MoveX(float value);
	void MoveY(float value);

public:
	AShip();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPawnMovementComponent* GetMovementComponent() const;
};
