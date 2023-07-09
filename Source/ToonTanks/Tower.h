// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaSeconds) override;

	void HandleDestruction();
	
protected:
	virtual void BeginPlay() override;
	
private:
	ATank* Tank;

	UPROPERTY(EditAnywhere,Category="Combat")
	float FireRange = 500.f;

	FTimerHandle FireRateTimerHandler;
	float FireRate = 2.f;
	void CheckFireCondition();
	bool InFireRange();
};
