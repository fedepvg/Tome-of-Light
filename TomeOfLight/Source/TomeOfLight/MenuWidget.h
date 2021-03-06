// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class TOMEOFLIGHT_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UPanelWidget* MenuPanel;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* PlayButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* ExitButton;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<class UWorld> GameLevel;

	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintCallable)
	void PlayGame() const;

	UFUNCTION(BlueprintCallable)
	void ExitGame();
};
