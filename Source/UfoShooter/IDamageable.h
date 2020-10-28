// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UFOSHOOTER_API IDamageable : public UInterface
{
public:
	virtual void DealDamage(int damage);
};
