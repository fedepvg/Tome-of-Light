// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "EnemySpawner.generated.h"

UCLASS()
class TOMEOFLIGHT_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	UPROPERTY(EditAnywhere)
	float ElementalSpawnRate;

	UPROPERTY(EditAnywhere)
	float SeekerSpawnRate;
	
	UPROPERTY(EditAnywhere)
	AActor* PlayerReference;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> ElementalClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> SeekerClass;

	UPROPERTY(EditAnywhere)
	TArray<class ATriggerBox*> SpawnAreas;

	FTimerHandle ElementalSpawnTimer;
	FTimerHandle SeekerSpawnTimer;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void SpawnEnemy(TSubclassOf<AActor> EnemyClass);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
