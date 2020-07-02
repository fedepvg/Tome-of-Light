// Fill out your copyright notice in the Description page of Project Settings.


#include "Damageable.h"
#include "HealthComponent.h"
#include "GameFramework/Actor.h"

// Add default functionality here for any IDamageable functions that are not pure virtual.

void IDamageable::OnTakeDamage(int Damage)
{
	UHealthComponent* HealthComponent = GetHealthComponent();
	if (HealthComponent == nullptr)
		return;

	//AActor* HealthComponentOwner = HealthComponent->GetOwner();

	//FDamageEvent DamageEvent;

	//Damage = HealthComponentOwner->TakeDamage(Damage, DamageEvent, nullptr, nullptr);


	HealthComponent->ApplyDamage(Damage);
}