// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/GameFramework/SpringArmComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "CollidingPawnMovementComponent.h"

#include "CollisionPawn.generated.h"

UCLASS()
class COLLISIONS_API ACollisionPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollisionPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bZoomingIn;
	float ZoomFactor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UParticleSystemComponent *OurParticleSystem;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;

	UCameraComponent* Camera;
	
	class UCollidingPawnMovementComponent *OurMovementComponent;
	
	virtual UPawnMovementComponent* GetMovementComponent() const override;


	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float AxisValue);
	void TurnYaw(float AxisValue);

	void ParticleToggle();
	void ZoomIn();
	void ZoomOut();
};
