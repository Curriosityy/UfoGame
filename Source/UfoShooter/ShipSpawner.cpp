// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipSpawner.h"
#include "Ships\Ship.h"
#include "Ships\AIMovementComponent.h"
#include "Ships\AiBehaviours\SinusoidMovement.h"
// Sets default values
AShipSpawner::AShipSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("RootMesh");
	RootComponent = mesh;

}

// Called when the game starts or when spawned
void AShipSpawner::BeginPlay()
{
	Super::BeginPlay();
	StartSpawning();
}

void AShipSpawner::StartSpawning() 
{
	spawnedShip = 0;
	GetWorldTimerManager().SetTimer(timeHandler, this, &AShipSpawner::SpawnShip, timeBetweenSpawns, true, 0.f);
}

void AShipSpawner::SpawnShip()
{

	FActorSpawnParameters params;
	auto ship = GetWorld()->SpawnActor<AShip>(aiShipPrefab);
	if (ship)
	{
		ship->SetActorLocation(GetActorLocation());
		ship->SetActorRotation(GetActorRotation());
		auto aiMovement = ship->FindComponentByClass<UAIMovementComponent>();
		aiMovement->Initialize(GetProvider());
		spawnedShip++;
		if (spawnedShip >= shipsToSpawn)
		{
			GetWorldTimerManager().ClearTimer(timeHandler);
		}
	}
}

IMoveVectorProvider* AShipSpawner::GetProvider()
{
	switch (movementType)
	{
		case AiMovementType::SinusMovement:
			return new SinusoidMovement(a, b, c);
		break;
	}
	return nullptr;
}
// Called every frame
void AShipSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

