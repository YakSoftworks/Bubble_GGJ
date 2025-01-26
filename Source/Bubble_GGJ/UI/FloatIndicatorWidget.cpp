// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatIndicatorWidget.h"
#include "Components/Image.h"
#include "Components/VerticalBox.h"

void UFloatIndicatorWidget::SetupWidget(bool IsUp)
{

	if (!IsUp) {
		//Setup Down - Up is the initial state

		TArray<UWidget*> floatContents = FloatBox->GetAllChildren();

		FloatBox->ClearChildren();

		for (int i = 0; i < floatContents.Num(); i++)
		{
			FloatBox->AddChild(floatContents[floatContents.Num() - 1 - i]);
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Indicator Setup"));

	FloatIcon->SetColorAndOpacity(FloatIconUnusedColor);

}

void UFloatIndicatorWidget::UseFloat()
{
	//Mark as Used
	if (bIsUsed) { return; }

	bIsUsed = true;

	//Change color of icon
	FloatIcon->SetColorAndOpacity(FloatIconUsedColor);

	UE_LOG(LogTemp, Warning, TEXT("Float Used"));
	

}

void UFloatIndicatorWidget::ReplenishFloat()
{
	if (!bIsUsed) { return; }

	//Do replenish
	bIsUsed = false;
	FloatIcon->SetColorAndOpacity(FloatIconUnusedColor);

}
