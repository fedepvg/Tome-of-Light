// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LivesWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOMEOFLIGHT_API ULivesWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* LifeImage1;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* LifeImage2;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* LifeImage3;

	TArray<UImage*> LivesArray;

	void NativeOnInitialized() override;
	
public:
	void UpdateLives();
};
