// Fill out your copyright notice in the Description page of Project Settings.


#include "SinusoidMovement.h"

SinusoidMovement::SinusoidMovement(float a, float omega, float theta)
{
	Tick = 0;
	A = a;
	Omega = omega;
	Theta = theta;
}


FVector SinusoidMovement::GetMoveVector(float tick)
{
	
	auto oldVector = FVector(Tick, GetSinus(Tick), 0);
	Tick += tick;
	auto newSinus = FVector(Tick, GetSinus(Tick), 0);
	return (newSinus-oldVector).GetSafeNormal();
}

float SinusoidMovement::GetSinus(float tick)
{
	return  A * FMath::Sin(Omega * tick + Theta);
}