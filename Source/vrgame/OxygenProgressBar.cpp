// Fill out your copyright notice in the Description page of Project Settings.


#include "OxygenProgressBar.h"	

void UOxygenProgressBar::StartFillingOxygen()
{
    int increase = 1;
    GetWorld()->GetTimerManager().SetTimer(SlowOxygenFillingTimer, this, &UOxygenProgressBar::AddOxygenSlowlyByTimer, 0.02f, true);
    StopOxygenDecrease();
    isFilling = true;
}

void UOxygenProgressBar::StopFillingOxygen()
{
    isFilling = false;
    StartOxygenDecrease();
    GetWorld()->GetTimerManager().ClearTimer(SlowOxygenFillingTimer);

}

void UOxygenProgressBar::Bind()
{
    AppearOnScreen();
	
}

void UOxygenProgressBar::AppearOnScreen()
{
    CurrentOpacity = 1.0f;
    OxygenBar->SetRenderOpacity(CurrentOpacity);
    OxygenPercentText->SetRenderOpacity(CurrentOpacity);
    OxygenBarLabel->SetRenderOpacity(CurrentOpacity);

}
void UOxygenProgressBar::StartFadeOut()
{
    CurrentOpacity = 1.0f;
    GetWorld()->GetTimerManager().SetTimer(OpacityTimerHandle, this, &UOxygenProgressBar::FadeOut, 0.01f, true);
}

void UOxygenProgressBar::FadeOut()
{
    CurrentOpacity -= 0.01f;
    OxygenBar->SetRenderOpacity(CurrentOpacity);
    OxygenPercentText->SetRenderOpacity(CurrentOpacity);
    OxygenBarLabel->SetRenderOpacity(CurrentOpacity);

    if (CurrentOpacity <= 0.01f) 
    {
        GetWorld()->GetTimerManager().ClearTimer(OpacityTimerHandle);
    }

}



void UOxygenProgressBar::StartOxygenDecrease() 
{
    AppearOnScreen();
    IsOxygenDecreasing = true;
    GetWorld()->GetTimerManager().SetTimer(OpacityTimerHandle, this, &UOxygenProgressBar::DecreaseOxygen, 1.0f, true);

}

void UOxygenProgressBar::DecreaseOxygen() 
{
    if (IsOxygenDecreasing == true) 
    {
        currentPercent--;
        if (currentPercent < 1)
        {
            currentPercent = 0;
            DieOfOxygenLoss();
        }
        SetPercent(currentPercent);
    }
    
}

void  UOxygenProgressBar::DieOfOxygenLoss()
{
    IsOxygenDecreasing = false;
    OxygenBarLabel->SetText(FText::FromString("DEAD"));

    GetWorld()->GetTimerManager().ClearTimer(OxygenDecreaseTimer);
    //gameover
}

void UOxygenProgressBar::StopOxygenDecrease()
{
    IsOxygenDecreasing = false;
    GetWorld()->GetTimerManager().ClearTimer(OxygenDecreaseTimer);
    //after SATURATION_TIME (about 5 seconds) start decreasing oxygen again.
    GetWorld()->GetTimerManager().SetTimer(OxygenSaturationTimer, this, &UOxygenProgressBar::StartOxygenDecrease, SATURATION_TIME, true);
}

void UOxygenProgressBar::AddOxygen(int amount) 
{
    currentPercent += amount;
    if (currentPercent > 100) {
        currentPercent = 100;

        StartFadeOut();
        StopOxygenDecrease();
    }
    SetPercent(currentPercent);
}

void UOxygenProgressBar::AddOxygenSlowlyByTimer()
{
    AddOxygen(1);
}



void UOxygenProgressBar::SetPercent(int new_percent)
{


    SetColor(new_percent);

    float percent_float = (float)new_percent / 100.0f;
    OxygenBar->SetPercent(percent_float);

   

    FString formatted_percent = FString::Printf(TEXT("%.0f"), percent_float * 100) + FString(TEXT("%"));
    if (percent_float < 0.3f) {
        OxygenBarLabel->SetText(FText::FromString("LOW OXYGEN"));
        OxygenBarLabel->SetColorAndOpacity(SlateRed);


    }
    else {
        OxygenBarLabel->SetText(FText::FromString("Oxygen Levels"));
        OxygenBarLabel->SetColorAndOpacity(SlateWhite);
    }
    OxygenPercentText->SetText(FText::FromString(formatted_percent));
}



void UOxygenProgressBar::SetColor(int new_percent) 
{
    int range = 50;
    float lerp_percent;
    if (new_percent > 99) {

        OxygenBar->SetFillColorAndOpacity(FullColor);
    }
    else if (new_percent > 50) {
        new_percent -= 50;
        lerp_percent = (float)new_percent / (float)range;

        FLinearColor InterpolatedColor = FLinearColor::LerpUsingHSV(MidColor, FullColor, lerp_percent);
        OxygenBar->SetFillColorAndOpacity(InterpolatedColor);
    }
    else {
        lerp_percent = (float)new_percent / (float)range;

        
        FLinearColor InterpolatedColor = FLinearColor::LerpUsingHSV(LowColor, MidColor, lerp_percent);
        OxygenBar->SetFillColorAndOpacity(InterpolatedColor);
    }


}