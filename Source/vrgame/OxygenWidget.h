// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "TimerManager.h"
#include "OxygenWidget.generated.h"

/**
 * 
 */
UCLASS()
class VRGAME_API UOxygenWidget : public UUserWidget
{
	GENERATED_BODY()


protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* OxygenLabel;

	UFUNCTION(BlueprintCallable)
	void SetText();

	UFUNCTION(BlueprintCallable)
		void StartCountdown();

	void DecreaseOxygen();

	int percentOxygen = 100;
};
g