// Fill out your copyright notice in the Description page of Project Settings.


#include "TOLPlayerController.h"
#include "GameFramework/PlayerState.h"
ATOLPlayerController::ATOLPlayerController()
{
}

void ATOLPlayerController::BeginPlay()
{
	Super::BeginPlay();

	GetPlayerState<APlayerState>()->Score = 0.f;
}


float ATOLPlayerController::GetScore() const
{
	return GetPlayerState<APlayerState>()->Score;
}

void ATOLPlayerController::SetScore(float value)
{
	GetPlayerState<APlayerState>()->Score = value;
	//UE_LOG(LogTemp, Log, TEXT("%f"), GetPlayerState<APlayerState>()->Score);
}
