// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveVectorProvider.h"
/**
 * 
 */
class UFOSHOOTER_API SinusoidMovement:public IMoveVectorProvider
{
public:
	SinusoidMovement();
	~SinusoidMovement();
	virtual FVector GetMoveVector(float tick) override;
};
