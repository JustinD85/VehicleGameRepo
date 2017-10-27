// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileCarPlayerController.h"


	



void AProjectileCarPlayerController::BeginPlay()
{
	Super::BeginPlay();


	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));


	AProjectileCar* ControlledCar = GetControlledProjectileCar();
	if (!ControlledCar) {

		UE_LOG(LogTemp, Warning, TEXT("Not Possessed Tank"));
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("Possessed %s"), *(ControlledCar->GetName()));
	}
}

void AProjectileCarPlayerController::Tick(float DeltaTime) 
{

	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}




AProjectileCar* AProjectileCarPlayerController::GetControlledProjectileCar() const 
{

	return Cast < AProjectileCar>(GetPawn());
}

void AProjectileCarPlayerController::AimTowardsCrosshair() 
{
	if (!GetControlledProjectileCar()) { return; }
	
	FVector OUTHitLocation; //Out parameter
	if(GetSightRayHitLocation(OUTHitLocation)) // Has "side-effect", is giong to line trace
	{

		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OUTHitLocation.ToString());

			
			//If hits the landscape
				// tell controlled tank to aim at point
	}

}
//Get world location through crosshair(linetrace thru crosshair), true if hits landscape
bool AProjectileCarPlayerController::GetSightRayHitLocation(FVector& OUTHitLocation) const 
{
	OUTHitLocation = FVector(1.0);
	return true;
}