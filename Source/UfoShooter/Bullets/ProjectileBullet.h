// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet.h"
#include "ProjectileBullet.generated.h"

/**
 * 
 */
class UProjectileMovementComponent;
UCLASS()
class UFOSHOOTER_API AProjectileBullet : public ABullet
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* staticMesh;
	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* movement;
	virtual void BulletHit(AActor* OverlappedActor, AActor* OtherActor) override;
public:
	AProjectileBullet();
	virtual void BeginPlay() override;
	virtual void Fire() override;
};
