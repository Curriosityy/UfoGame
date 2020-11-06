// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectPool.generated.h"

UCLASS()
class UFOSHOOTER_API AObjectPool : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectPool();
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ObjectToPool;
	UPROPERTY(EditAnywhere)
	int startingObjectSize = 30;

	AActor* GetObjectFromPool();
	void AddObjectToPool(AActor* objectToPool);

protected:
	TQueue<AActor*>* pool;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
