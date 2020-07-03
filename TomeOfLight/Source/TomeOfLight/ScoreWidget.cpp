// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UScoreWidget::UpdateScoreText(int Score) const
{
	ScoreText->SetText(FText::FromString(FString::FromInt(Score)));
}
