// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	APlayerController* GetTAnkPlayerController() const{return  TankPlayerController;}

	bool bAlive = true;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
private:
	UPROPERTY(EditAnywhere, Category="Components")
	USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere, Category="Components")
	UCameraComponent* CameraComp;

	void Move(float Value);
	void Turn(float Value);

	UPROPERTY(EditAnywhere,Category="Movement")
	float Speed = 100.f;
	
	UPROPERTY(EditAnywhere,Category="Movement")
	float Rotation = 45.f;
	
	APlayerController* TankPlayerController;
	
};
