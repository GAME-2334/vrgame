// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Class.h"
#include "Widgets/SWidget.h"
#include "Components/Widget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

#include "OxygenProgressBar.generated.h"


/**
 * 
 */
UCLASS()
class VRGAME_API UOxygenProgressBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	int currentPercent = 100;
	int oxygen_unit_counter;
	int max_oxygen_to_add;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UProgressBar* OxygenBar;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* OxygenPercentText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* OxygenBarLabel;

	bool isFilling;
	UFUNCTION(BlueprintCallable)
		void StartFillingOxygen(int max_oxygen);

	UFUNCTION(BlueprintCallable)
		void StopFillingOxygen();

	UFUNCTION(BlueprintCallable)
		void Bind();



	FTimerHandle OpacityTimerHandle;

	FTimerHandle OxygenDecreaseTimer;

	FTimerHandle SlowOxygenFillingTimer;


	//if the oxygen is saturated, after x seconds start decreasing again.
	FTimerHandle OxygenSaturationTimer;
	float SATURATION_TIME = 5.0f;

	float CurrentOpacity;
	bool IsOxygenDecreasing = false;

	UFUNCTION(BlueprintCallable)
		void StartOxygenDecrease();

	void DecreaseOxygen();

	void StopOxygenDecrease();

	void StartFadeOut();

	void AppearOnScreen();

	void FadeOut();

	UFUNCTION(BlueprintCallable)
		void AddOxygen(int amount);

	UFUNCTION(BlueprintCallable)
		void AddOxygenSlowlyByTimer();


	UFUNCTION(BlueprintCallable)
		void DieOfOxygenLoss();

	void SetPercent(int new_percent);

	
	FSlateColor SlateRed = FSlateColor(FLinearColor::Red);
	FSlateColor SlateWhite = FSlateColor(FLinearColor::White);

	FLinearColor FullColor = FLinearColor(0.059896f, 1.0f, 0.797975f, 1.0f);
	FLinearColor MidColor = FLinearColor(1.0f, 0.855065f, 0.19498f, 1.0f);
	FLinearColor LowColor = FLinearColor(0.609375f, 0.053683f, 0.022217f, 1.0f);

	void SetColor(int new_percent);

};
