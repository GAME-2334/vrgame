// Fill out your copyright notice in the Description page of Project Settings.


#include "RayCastChar.h"

// Sets default values
ARayCastChar::ARayCastChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARayCastChar::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void ARayCastChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARayCastChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

