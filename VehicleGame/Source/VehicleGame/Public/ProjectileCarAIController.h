// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ProjectileCar.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "ProjectileCarAIController.generated.h"

/**
 * 
 */
UCLASS()
class VEHICLEGAME_API AProjectileCarAIController : public AAIController
{
	GENERATED_BODY()
public:
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
private:
	AProjectileCar* GetControlledProjectileCar() const;
	AProjectileCar* GetPlayerProjectileCar() const;




	
};
