// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OxygenTank.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VRGAME_API UOxygenTank : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOxygenTank();
	UFUNCTION(BlueprintImplementableEvent, Category = "Oxygen")
		void FillOxygen();
	virtual void FillOxygen_Implementation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")

	TSubclassOf<class UOxygenProgressBar> OxygenProgressBarInScene;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
