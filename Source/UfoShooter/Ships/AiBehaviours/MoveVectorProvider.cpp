// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveVectorProvider.h"

// Add default functionality here for any IMoveVectorProvider functions that are not pure virtual.
void IMoveVectorProvider::Initialize(float y0, float ymax, float ymin)
{
	Tick = 0;
	Y0 = y0;
	Ymax = ymax;
	Ymin = ymin;
}

FVector IMoveVectorProvider::GetMoveVector(float DeltaTime)
{
	check(0 && "This method need to be overrided");
	return FVector();
}
