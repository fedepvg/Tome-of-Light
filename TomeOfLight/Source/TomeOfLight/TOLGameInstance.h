// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TOLGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TOMEOFLIGHT_API UTOLGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	float GetPreviousScore() { return PrevScore; }
	void SetPreviousGameScore(float Score) { PrevScore = Score; }
private:
	int PrevScore = 0;
};
