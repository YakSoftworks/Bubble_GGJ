// Fill out your copyright notice in the Description page of Project Settings.

#include "FloatCounterWidget.h"
#include "FloatIndicatorWidget.h"
#include "Components/HorizontalBox.h"

void UFloatCounterWidget::AddOneToCounter()
{
	UFloatIndicatorWidget* CounterWidget = CreateWidget<UFloatIndicatorWidget>(this, FloatIndicatorClass);

	if(!FloatIndicators.IsEmpty())
	{
		if(FloatIndicators[FloatIndicators.Num()-1]->bIsUp)
		{
			//Setup Down
			CounterWidget->SetupWidget(false);
		}
		else 
		{
			//Setup Up
			CounterWidget->SetupWidget(true);
		}
	}
	else {
		//Setup Up
		CounterWidget->SetupWidget(true);
	}
	numberOfFloats++;
	FloatIndicators.Add(CounterWidget);
	CounterBox->AddChild(CounterWidget);
	CounterWidget->SetVisibility(ESlateVisibility::Visible);
	UE_LOG(LogTemp, Warning, TEXT("Added New Floater"));

}

void UFloatCounterWidget::UseJump()
{
	if (FloatIndicators.IsEmpty()) { return; }

	
	//Mark the last float as used
	int floatToUse = FloatIndicators.Num() - 1 - numberOfFloatsUsed;

	UE_LOG(LogTemp, Warning, TEXT("Marking float %d"), floatToUse);

	if (floatToUse > -1) {
		FloatIndicators[floatToUse]->UseFloat();
		numberOfFloatsUsed++;
		
	}
}

void UFloatCounterWidget::ReplenishJumps()
{

	if (numberOfFloats < 1) { return; }
	//All floats as unused
	numberOfFloatsUsed = 0;
	for (UFloatIndicatorWidget* FloatIndicator : FloatIndicators)
	{
		FloatIndicator->ReplenishFloat();
	}

}
