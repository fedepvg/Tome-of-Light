// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOverWidget.h"
#include "TOLGameInstance.h"
#include "UMG/Public/Components/TextBlock.h"

void UGameOverWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	UTOLGameInstance* GameInstance = Cast<UTOLGameInstance>(GetGameInstance());
	if (GameInstance != nullptr)
	{
		SetScoreText(GameInstance->GetPreviousScore());
	}
}

void UGameOverWidget::SetScoreText(int Score)
{
	ScoreText->SetText(FText::FromString(FString::FromInt(Score)));
}
