// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOMEOFLIGHT_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), meta = (BindWidget))
	class UTextBlock* ScoreText;

public:
	
	void UpdateScoreText(int Score) const;
};
