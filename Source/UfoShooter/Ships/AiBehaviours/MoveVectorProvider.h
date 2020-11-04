// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MoveVectorProvider.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMoveVectorProvider : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UFOSHOOTER_API IMoveVectorProvider
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION()
	virtual FVector GetMoveVector(float tick);
	void Initialize(float y0, float ymax, float ymin);
protected:
	float Tick = 0;
	float Y0 = 0;
	float Ymax = 0;
	float Ymin = 0;
};
