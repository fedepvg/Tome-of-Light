// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Components/BoxComponent.h"
#include "Engine/TriggerBox.h"
#include "Kismet/KismetMathLibrary.h"
#include "ElementalPawn.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(SpawnTimer, this, &ThisClass::SpawnEnemy, BaseSpawnRate, true);
}

void AEnemySpawner::SpawnEnemy()
{
	int SpawnAreaIndex = FMath::RandRange(0, SpawnAreas.Max()-1);
	FVector SpawnOrigin = SpawnAreas[SpawnAreaIndex]->GetCollisionComponent()->Bounds.Origin;
	FVector SpawnExtent = SpawnAreas[SpawnAreaIndex]->GetCollisionComponent()->Bounds.BoxExtent;
	FVector SpawnPoint = UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);

	AActor* SpawnedActor = GetWorld()->SpawnActor(EnemyClass, &SpawnPoint);
	AElementalPawn* Enemy = Cast<AElementalPawn>(SpawnedActor);
	if(Enemy != nullptr)
	{
		Enemy->SetMovementVector((PlayerReference->GetActorLocation() - SpawnPoint).GetSafeNormal());
	}
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

