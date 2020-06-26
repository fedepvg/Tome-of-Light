// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "ElementalPawn.generated.h"

UCLASS()
class TOMEOFLIGHT_API AElementalPawn : public ADefaultPawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AElementalPawn();

protected:
	//UPROPERTY(EditDefaultsOnly)
	//class UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly)
	float Speed;

	FVector MovementVector;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE void SetMovementVector(FVector NewMovementVector) { MovementVector = NewMovementVector; }
};
