// Fill out your copyright notice in the Description page of Project Settings.


#include "TestLocomotion.h"

// Sets default values
ATestLocomotion::ATestLocomotion()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestLocomotion::BeginPlay()
{
	Super::BeginPlay();
	// Get reference to the motion controller component
	MotionController = GetWorld()->GetFirstPlayerController()->GetMotionController();
	
}

// Called every frame
void ATestLocomotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestLocomotion::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

