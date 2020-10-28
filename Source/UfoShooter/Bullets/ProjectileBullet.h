// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet.h"
#include "ProjectileBullet.generated.h"

/**
 * 
 */
UCLASS()
class UFOSHOOTER_API AProjectileBullet : public ABullet
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* staticMesh;
public:
	AProjectileBullet();
	virtual void BeginPlay() override;
	virtual void Fire() override;
};
