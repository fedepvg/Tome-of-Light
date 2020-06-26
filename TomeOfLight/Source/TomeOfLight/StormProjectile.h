// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TomeOfLightProjectile.h"
#include "StormProjectile.generated.h"

/**
 * 
 */
UCLASS()
class TOMEOFLIGHT_API AStormProjectile : public ATomeOfLightProjectile
{
	GENERATED_BODY()

private:

	AStormProjectile();
	UPROPERTY(EditAnywhere, Category = "Bullet", meta = (AllowPrivateAccess = "true"))
	float SizeModifier;
	
	void Tick(float DeltaSeconds) override;
};
