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

AProjectileCar* AProjectileCarPlayerController::GetControlledProjectileCar() const {

	return Cast < AProjectileCar>(GetPawn());
}
