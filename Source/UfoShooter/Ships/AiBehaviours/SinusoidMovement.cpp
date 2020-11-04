// Fill out your copyright notice in the Description page of Project Settings.


#include "SinusoidMovement.h"

SinusoidMovement::SinusoidMovement()
{
	Tick = 0;
}

SinusoidMovement::~SinusoidMovement()
{
}

FVector SinusoidMovement::GetMoveVector(float tick)
{
	
	auto oldVector = FVector(Tick, FMath::Sin(Tick), 0);
	Tick += tick;
	auto newSinus = FVector(Tick, FMath::Sin(Tick),0);
	return (newSinus-oldVector).GetSafeNormal();
}
