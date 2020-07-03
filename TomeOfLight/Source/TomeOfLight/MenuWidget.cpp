// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

#include "UMG/Public/Components/PanelWidget.h"
#include "UMG/Public/Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"

void UMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMenuWidget::PlayGame() const
{
	UGameplayStatics::OpenLevel(this, FName(*GameLevel.GetAssetName()));
}

void UMenuWidget::ExitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}