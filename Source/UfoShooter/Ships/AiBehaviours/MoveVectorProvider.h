// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class UFOSHOOTER_API IMoveVectorProvider
{
public:
	virtual FVector GetMoveVector(float tick);
	void RestartTicks();
	~IMoveVectorProvider();
protected:
	float Tick = 0;
};
