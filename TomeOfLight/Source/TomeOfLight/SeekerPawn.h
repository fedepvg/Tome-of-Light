// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ElementalPawn.h"
#include "SeekerPawn.generated.h"

/**
 * 
 */
UCLASS()
class TOMEOFLIGHT_API ASeekerPawn : public AElementalPawn
{
	GENERATED_BODY()
	
protected:
	/** max turn rate per frame */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Movement)
	float MaximumTurnRate;
	
public:
	virtual void Tick(float DeltaTime) override;
};
