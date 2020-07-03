// Fill out your copyright notice in the Description page of Project Settings.


#include "SeekerPawn.h"

void ASeekerPawn::Tick(float DeltaTime)
{
	FVector vectorToPlayer = PlayerActor->GetActorLocation() - GetActorLocation();

	float movementSize = MovementVector.Size();
	
	FVector upVector = FVector::CrossProduct(MovementVector, vectorToPlayer);

	float angleBetweenVectors = FMath::Acos(FVector::DotProduct(MovementVector.GetSafeNormal(1.0f), vectorToPlayer.GetSafeNormal(1.0f)));

	float turnSign = 1.f;
	if (angleBetweenVectors <= 0.f)
		turnSign = -1.f;
	
	MovementVector = MovementVector.RotateAngleAxis(DeltaTime * turnSign * MaximumTurnRate, upVector);
	MovementVector.Normalize();
	MovementVector = MovementVector * movementSize;
	//MovementVector = PlayerActor->GetActorLocation() - GetActorLocation();
	Super::Tick(DeltaTime);
}
