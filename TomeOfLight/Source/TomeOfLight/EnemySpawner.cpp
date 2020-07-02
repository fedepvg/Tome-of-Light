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

	FTimerDelegate ElementalSpawnDelegate;
	ElementalSpawnDelegate.BindUObject(this, &ThisClass::SpawnEnemy, ElementalClass);
	FTimerDelegate SeekerSpawnDelegate;
	ElementalSpawnDelegate.BindUObject(this, &ThisClass::SpawnEnemy, SeekerClass);
	
	GetWorld()->GetTimerManager().SetTimer(ElementalSpawnTimer, ElementalSpawnDelegate,ElementalSpawnRate, true);
	GetWorld()->GetTimerManager().SetTimer(SeekerSpawnTimer, SeekerSpawnDelegate, SeekerSpawnRate, true);
}

void AEnemySpawner::SpawnEnemy(TSubclassOf<AActor> EnemyClass)
{
	if (EnemyClass != nullptr)
	{
		int SpawnAreaIndex = FMath::RandRange(0, SpawnAreas.Max() - 1);
		FVector SpawnOrigin = SpawnAreas[SpawnAreaIndex]->GetCollisionComponent()->Bounds.Origin;
		FVector SpawnExtent = SpawnAreas[SpawnAreaIndex]->GetCollisionComponent()->Bounds.BoxExtent;
		FVector SpawnPoint = UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);

		AActor* SpawnedActor = GetWorld()->SpawnActor(EnemyClass, &SpawnPoint);
		AElementalPawn* Enemy = Cast<AElementalPawn>(SpawnedActor);
		if (Enemy != nullptr)
		{
			Enemy->InitializaEnemy(PlayerReference);
		}

	}
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

