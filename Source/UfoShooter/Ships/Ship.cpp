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
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");

	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	meshComponent->SetRelativeRotation(FQuat::MakeFromEuler(FVector(0, 0, -90)));
	meshComponent->SetRelativeLocation(FVector(400, -500, 0));
	meshComponent->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepWorldTransform);

	movementComponent = CreateDefaultSubobject<UShipMovementComponent>("MovementComponent");
	movementComponent->UpdatedComponent = RootComponent;

	if(startGunBP)
		currentGun = GetWorld()->SpawnActor<AGun>(startGunBP);
}

void AShip::BeginPlay()
{
	Super::BeginPlay();
	hp = maxHP;
	StartShooting();
}

void AShip::StartShooting()
{
	GetWorldTimerManager().SetTimer(timeHandler, this, &AShip::Shoot, currentGun->GetFirerate(), true, .0f);
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

void AShip::Shoot()
{
	currentGun->FireProjectile();
}

void AShip::SwitchGun(AGun* newGun)
{
	StopShooting();
	currentGun = newGun;
	StartShooting();
}

void AShip::StopShooting()
{
	GetWorldTimerManager().ClearTimer(timeHandler);
}

void AShip::Die()
{
}

UPawnMovementComponent* AShip::GetMovementComponent() const
{
	return movementComponent;
}

AGun* AShip::GetCurrentGun() const
{
	return currentGun;
}

void AShip::DealDamage(int damage)
{
	hp -= damage;
	if (damage <= 0)
	{
		Die();
	}
}