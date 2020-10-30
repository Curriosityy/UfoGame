// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"
#include "ShipMovementComponent.h"
#include <UfoShooter\Guns\Gun.h>
// Sets default values
AShip::AShip()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add("Ship");
	maxHP = 100;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	meshComponent->SetRelativeRotation(FQuat::MakeFromEuler(FVector(0, 0, -90)));
	meshComponent->SetRelativeLocation(FVector(400, -500, 0));
	meshComponent->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepWorldTransform);

	movementComponent = CreateDefaultSubobject<UShipMovementComponent>(TEXT("MovementComponent"));
	movementComponent->UpdatedComponent = RootComponent;
}

void AShip::BeginPlay()
{
	Super::BeginPlay();
	hp = maxHP;
}


void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

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
		movementComponent->AddInputVector(GetActorRightVector() * value);
	}
}
void AShip::MoveY(float value)
{
	if (movementComponent && (movementComponent->UpdatedComponent == RootComponent))
	{
		movementComponent->AddInputVector(GetActorForwardVector() * value);
	}
}


void AShip::Die()
{
	
}

UPawnMovementComponent* AShip::GetMovementComponent() const
{
	return movementComponent;
}

void AShip::DealDamage(int damage)
{
	hp -= damage;
	if (damage <= 0)
	{
		Die();
	}
}