// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPool.h"

// Sets default values
AObjectPool::AObjectPool()
{
	PrimaryActorTick.bCanEverTick = true;
}

AActor* AObjectPool::GetObjectFromPool()
{
	AActor* returnActor;
	if (!pool->Dequeue(returnActor))
	{
		returnActor = GetWorld()->SpawnActor(ObjectToPool);
		returnActor->SetActorHiddenInGame(true);
	}
	return returnActor;
}

void AObjectPool::AddObjectToPool(AActor* objectToPool)
{
	objectToPool->SetActorHiddenInGame(true);
	pool->Enqueue(objectToPool);
}

// Called when the game starts or when spawned
void AObjectPool::BeginPlay()
{
	Super::BeginPlay();
	pool = new TQueue<AActor*>();
	auto world = GetWorld();
	for (int i = 0; i < startingObjectSize; i++)
	{
		AddObjectToPool(world->SpawnActor(ObjectToPool));
	}
}

void AObjectPool::BeginDestroy()
{
	Super::BeginDestroy();
	if(pool!=nullptr)
		pool->~TQueue();
}

void AObjectPool::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

