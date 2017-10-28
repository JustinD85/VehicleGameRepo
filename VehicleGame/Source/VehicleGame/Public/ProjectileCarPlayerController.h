// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ProjectileCar.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ProjectileCarPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLEGAME_API AProjectileCarPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AProjectileCar* GetControlledProjectileCar() const;
	
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
private:
	//Start moving barrel so that a shot would hit where cross hair intersects
	//the world.
	void AimTowardsCrosshair();
	
	//Return OUT parameter, true if hti landscape
	bool GetSightRayHitLocation(FVector& OUTHitLocation) const;
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.333;

	FVector* WorldDirection;
	bool GetLookDirection(FVector2D  ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

};
