// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileCar.h"


// Sets default values
AProjectileCar::AProjectileCar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectileCar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AProjectileCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

