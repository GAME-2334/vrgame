// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableComponent.h"
#include "InteractableComponentDerived.generated.h"

/**
 * 
 */

UCLASS( Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class VRGAME_API UInteractableComponentDerived : public UInteractableComponent
{
	GENERATED_BODY()
		virtual void Interact() override;
};
