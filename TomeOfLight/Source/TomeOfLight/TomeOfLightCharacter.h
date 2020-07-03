// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Damageable.h"
#include "TomeOfLightCharacter.generated.h"

class UInputComponent;

UCLASS(config=Game)
class ATomeOfLightCharacter : public ACharacter, public IDamageable
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	class USkeletalMeshComponent* Mesh1P;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* FP_MuzzleLocation;

	/** Gun mesh: VR view (attached to the VR controller directly, no arm, just the actual gun) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* VR_Gun;

	/** Location on VR gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* VR_MuzzleLocation;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	/** Motion controller (right hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* R_MotionController;

	/** Motion controller (left hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* L_MotionController;

	class UHealthComponent* GetHealthComponent() const override;

public:
	ATomeOfLightCharacter();

protected:
	virtual void BeginPlay();

public:
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector GunOffset;

	/** Roman Fireball firerate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tomes)
	float RomanFireballFirerate;

	/** Sumerian Storm Firerate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tomes)
	float SumerianStormFirerate;

	/** Sumerian Storm projectile spread */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tomes)
	float SumerianStormSpread;

	/** Sumerian Storm projectile ammount */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tomes)
	int SumerianStormProjectileCount;

	/** if true, Sumerian Storm is ready to fire*/
	bool IsSumerianStormReady;
	
	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class ATomeOfLightProjectile> ProjectileClass;

	/** Fireball class to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tomes)
	TSubclassOf<class ATomeOfLightProjectile> RomanFireballClass;

	/** Fireball class to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tomes)
	TSubclassOf<class ATomeOfLightProjectile> SumerianStormProjectileClass;
	
	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;

	/** Whether to use motion controller location for aiming. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	uint32 bUsingMotionControllers : 1;

	void OnEnemyKilled(int Score) const;

	UFUNCTION()
	void OnDamageRecived();
	
protected:
	
	/** Fires a projectile. */
	void OnFire();
	
	/** Fires a Fireball */
	void FireRomanFireball();
	
	/** Begin firing Roman Fireball*/
	void BeginRomanFireball();

	/** Stop firing Roman Fireball */
	void StopRomanFireball();

	/** Fire a volley of Sumerian Storm Projectiles */
	void FireSumerianStorm();

	/** Begin firing Sumerian Storm */
	void BeginSumerianStorm();

	/** Stop firing Sumerian Storm */
	void StopSumerianStorm();
	
	/** Resets HMD orientation and position in VR. */
	void OnResetVR();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	struct TouchData
	{
		TouchData() { bIsPressed = false;Location=FVector::ZeroVector;}
		bool bIsPressed;
		ETouchIndex::Type FingerIndex;
		FVector Location;
		bool bMoved;
	};
	void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);
	TouchData	TouchItem;

	FTimerHandle RomanFireballTimerHandle;
	FTimerHandle SumerianStormTimerHandle;

	UPROPERTY(EditDefaultsOnly)
	float SumerianStormBulletRange;

	UPROPERTY(EditAnywhere)
	UHealthComponent* HealthComponent;

	void Destroyed() override;
	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

	/* 
	 * Configures input for touchscreen devices if there is a valid touch interface for doing so 
	 *
	 * @param	InputComponent	The input component pointer to bind controls to
	 * @returns true if touch controls were enabled.
	 */
	bool EnableTouchscreenMovement(UInputComponent* InputComponent);

public:
	/** Returns Mesh1P subobject **/
	FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};

