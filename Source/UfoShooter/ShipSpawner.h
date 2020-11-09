// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShipSpawner.generated.h"

UENUM()
enum AiMovementType
{
	SinusMovement     UMETA(DisplayName = "Sinusoid (a*sin(b*DeltaTime+c))")
};
class AShip;
class IMoveVectorProvider;
class UAIMovementComponent;
UCLASS()
class UFOSHOOTER_API AShipSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShipSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void StartSpawning();
	void SpawnShip();
	IMoveVectorProvider* GetProvider();
	FTimerHandle timeHandler;
	UPROPERTY(EditAnywhere)
		int shipsToSpawn;
	UPROPERTY(EditAnywhere)
		float timeBetweenSpawns;
	UPROPERTY(EditAnywhere)
	int spawnedShip = 0;


	UPROPERTY(EditAnywhere)
		TSubclassOf<AShip> aiShipPrefab;

	UPROPERTY(EditAnywhere, Category = AiMovementType)
		TEnumAsByte<AiMovementType> movementType;
	UPROPERTY(EditAnywhere, Category = AiMovementType)
		int a;
	UPROPERTY(EditAnywhere, Category = AiMovementType)
		float b;
	UPROPERTY(EditAnywhere, Category = AiMovementType)
		float c;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

