// Fill out your copyright notice in the Description page of Project Settings.


#include "SeekerPawn.h"

void ASeekerPawn::Tick(float DeltaTime)
{
	MovementVector = PlayerActor->GetActorLocation() - GetActorLocation();
	Super::Tick(DeltaTime);
}
