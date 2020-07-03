// Fill out your copyright notice in the Description page of Project Settings.


#include "StormProjectile.h"
#include "GameFramework/WorldSettings.h"
#include "Components/SphereComponent.h"

AStormProjectile::AStormProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AStormProjectile::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	FTransform NTransform = CollisionComp->GetRelativeTransform();
	if (NTransform.GetScale3D().X > 0.0f)
	{
		NTransform.SetScale3D(NTransform.GetScale3D() - SizeModifier * DeltaSeconds);
		CollisionComp->SetRelativeTransform(NTransform);
	}
	else
		Destroy();
	//CollisionComp->SetSphereRadius(CollisionComp->GetShapeScale() * SizeModifier * DeltaSeconds);
	//UE_LOG(LogTemp, Log, TEXT("scalex, %f"), CollisionComp->GetRelativeTransform().GetScale3D().X);
}
