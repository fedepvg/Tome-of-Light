// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TomeOfLightGameMode.h"
#include "TomeOfLightHUD.h"
#include "TomeOfLightCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "TOLGameInstance.h"
#include "GameFramework/PlayerState.h"

ATomeOfLightGameMode::ATomeOfLightGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATomeOfLightHUD::StaticClass();
}

void ATomeOfLightGameMode::OnPlayerDeath(APlayerController* Player)
{
	UTOLGameInstance* GameInstance = Cast<UTOLGameInstance>(GetGameInstance());
	if(GameInstance!=nullptr)
	{
		GameInstance->SetPreviousGameScore(Player->GetPlayerState<APlayerState>()->Score);
	}

	UGameplayStatics::OpenLevel(this, FName(*GameOverLevel.GetAssetName()));
}
