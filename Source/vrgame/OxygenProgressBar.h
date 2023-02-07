// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Class.h"
#include "Widgets/SWidget.h"
#include "Components/Widget.h"
#include "Components/ProgressBar.h"
#include "OxygenProgressBar.generated.h"

/**
 * 
 */
UCLASS()
class VRGAME_API UOxygenProgressBar : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UProgressBar* OxygenBar;

	UFUNCTION(BlueprintCallable)
		void TestBind();
};
