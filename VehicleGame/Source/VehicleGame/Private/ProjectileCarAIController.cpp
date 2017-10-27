// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileCarAIController.h"
#include "ProjectileCar.h"





void AProjectileCarAIController::BeginPlay()
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

AProjectileCar* AProjectileCarAIController::GetControlledProjectileCar() const {

	return Cast <AProjectileCar>(GetPawn());
}

AProjectileCar* AProjectileCarAIController::GetPlayerProjectileCar() const {

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<AProjectileCar>(PlayerPawn);
}