// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileCarPlayerController.h"
#include "GameFramework/Actor.h"


	



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
	if(GetSightRayHitLocation(OUTHitLocation)) // Has "side-effect", is going to line trace
	{

		GetControlledProjectileCar()->AimAT(OUTHitLocation);

			
			//If hits the landscape
				// tell controlled tank to aim at point
	}

}
//Get world location through cross hair(line trace thru cross hair), true if hits landscape
bool AProjectileCarPlayerController::GetSightRayHitLocation(FVector& OUTHitLocation) const 
{

	//Find the cross hair position
	int32 ViewportSizeX, ViewPortSizeY;
	GetViewportSize(ViewportSizeX, ViewPortSizeY);

	//"De-project" the screen position of the cross hair to a world direction
	FVector LookDirection;
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewPortSizeY * CrosshairYLocation);
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Line-trace along that look direction, and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, OUTHitLocation);
	}	
	return true;
}

bool AProjectileCarPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OUTHitLocation) const{

	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		OUTHitLocation = HitResult.Location;
		return true;
	}
	return false; //line trace doesn't hit anything
}
	



bool AProjectileCarPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector CameraWorldLocation; // To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}