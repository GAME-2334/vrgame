// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableComponentDerived.h"

void UInteractableComponentDerived::Interact()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("overridden function called"));
    // Get the current transform of the actor
    FTransform CurrentTransform = GetOwner()->GetActorTransform();

    // Create a new transform with the Z component moved up by the given distance
    FTransform NewTransform = CurrentTransform;
    NewTransform.AddToTranslation(FVector(0.0f, 0.0f, 20));

    // Set the new transform for the actor
    GetOwner()->SetActorTransform(NewTransform);


    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("I've moved up."));
}
