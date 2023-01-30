// Fill out your copyright notice in the Description page of Project Settings.


#include "OxygenWidget.h"

void UOxygenWidget::SetText()
{
	OxygenLabel->SetText(FText::FromString("Current Oxygen:"));
	OxygenLabel->SetText(FText::AsNumber(percentOxygen));
}

void UOxygenWidget::StartCountdown()
{
	FTimerHandle MemberTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(MemberTimerHandle, this, &UOxygenWidget::DecreaseOxygen, 1.0f, true, 2.0f);  
}

void UOxygenWidget::DecreaseOxygen() 

{
	percentOxygen--;
	OxygenLabel->SetText(FText::AsNumber(percentOxygen));
}