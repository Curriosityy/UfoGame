// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveVectorProvider.h"
/**
 * 
 */
class UFOSHOOTER_API SinusoidMovement:public IMoveVectorProvider
{
private:
	float A = 0;
	float Omega = 0;
	float Theta = 0; 
public:
	SinusoidMovement(float a, float omega, float theta);
	virtual FVector GetMoveVector(float tick) override;
	float GetSinus(float tick);
};
