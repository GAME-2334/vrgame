// Fill out your copyright notice in the Description page of Project Settings.


#include "OxygenTank.h"

// Sets default values for this component's properties
UOxygenTank::UOxygenTank()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//OxygenProgressBarInScene = 
	// ...
}

void UOxygenTank::FillOxygen_Implementation()
{
}


// Called when the game starts
void UOxygenTank::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOxygenTank::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

