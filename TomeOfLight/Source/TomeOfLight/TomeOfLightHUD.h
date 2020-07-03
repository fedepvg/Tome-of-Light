// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ScoreWidget.h"
#include "TomeOfLightHUD.generated.h"

UCLASS()
class ATomeOfLightHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATomeOfLightHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UScoreWidget> ScoreWidgetClass;

	UPROPERTY(BlueprintReadOnly)
	UScoreWidget* ScoreWidget;
	
	void BeginPlay() override;
	
public:
	
	void UpdateScore() const;
};

