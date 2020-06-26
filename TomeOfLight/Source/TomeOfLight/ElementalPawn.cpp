// Fill out your copyright notice in the Description page of Project Settings.


#include "ElementalPawn.h"
#include "Components/StaticMeshComponent.h"
#include "TomeOfLightCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AElementalPawn::AElementalPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCollisionComponent()->OnComponentHit.AddDynamic(this, &ThisClass::OnCollision);
	MovementComponent->SetComponentTickEnabled(true);
}

// Called when the game starts or when spawned
void AElementalPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AElementalPawn::OnCollision(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	IDamageable* Player = Cast<IDamageable>(OtherActor);
	if (Player != nullptr)
	{
		Player->OnTakeDamage(Damage);
		
	}
	Destroy();
}

// Called every frame
void AElementalPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(MovementComponent)
		MovementComponent->AddInputVector(MovementVector.IsNormalized() ? MovementVector : MovementVector.GetSafeNormal());
}

// Called to bind functionality to input
void AElementalPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
