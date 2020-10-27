// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"
#include "ShipMovementComponent.h"

// Sets default values
AShip::AShip()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	meshComponent->SetRelativeLocation(FVector(400, -500, 0));
	Tags.Add("Ship");
	maxHP = 100;
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	meshComponent->AddToRoot();
	//RootComponent = meshComponent;
	movementComponent = CreateDefaultSubobject<UShipMovementComponent>("MovementComponent");
	movementComponent->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	hp = maxHP;
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveX", this, &AShip::MoveX);
	PlayerInputComponent->BindAxis("MoveY", this, &AShip::MoveY);
}

void AShip::MoveX(float value)
{
	if (movementComponent && (movementComponent->UpdatedComponent == RootComponent))
	{
		UE_LOG(LogTemp, Warning, TEXT("Move %f"), value);
		movementComponent->AddInputVector(GetActorRightVector() * value);
	}
}
void AShip::MoveY(float value)
{
	if (movementComponent && (movementComponent->UpdatedComponent == RootComponent))
	{
		UE_LOG(LogTemp, Warning, TEXT("Move %f"), value);
		movementComponent->AddInputVector(GetActorForwardVector() * value);
	}
}

UPawnMovementComponent* AShip::GetMovementComponent() const
{
	return movementComponent;
}

