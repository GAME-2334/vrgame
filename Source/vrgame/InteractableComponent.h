// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractableComponent.generated.h"


UCLASS(Abstract, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class VRGAME_API UInteractableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractableComponent();

	UFUNCTION(BlueprintCallable, Category = "Interactions")
	virtual void Interact();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Interactions")
	void StartOutlining();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Interactions")
	void StopOutlining();

	UPROPERTY(EditAnywhere)
		int editnumber;
	UPROPERTY(EditAnywhere)
		UInteractableComponent* runme;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};