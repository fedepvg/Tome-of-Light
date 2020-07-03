// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDamageRecived);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOMEOFLIGHT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

	UPROPERTY(EditAnywhere)
	int Health;

	UPROPERTY()
	FOnDamageRecived OnDamageRecived;
	
	virtual void ApplyDamage(int Damage);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
