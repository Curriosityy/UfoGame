// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

class ABullet;
UCLASS()
class UFOSHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();
	float GetFirerate() const;
protected:
	UPROPERTY(EditAnywhere)
		float fireRate = 1.f;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABullet> bulletBP;
	virtual void BeginPlay() override;
	UWorld* world;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void FireProjectile();
};
