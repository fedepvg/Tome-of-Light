// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TOLPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOMEOFLIGHT_API ATOLPlayerController : public APlayerController
{
	GENERATED_BODY()

	ATOLPlayerController();

public:

	void BeginPlay() override;
	
	float GetScore() const;

	void SetScore(float value);
};
