// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "FloatCounterWidget.generated.h"

class UHorizontalBox;
class UFloatIndicatorWidget;
/**
 * 
 */
UCLASS()
class BUBBLE_GGJ_API UFloatCounterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	int32 numberOfFloats = 0;
	int32 numberOfFloatsUsed = 0;

	void AddOneToCounter();

	void UseJump();

	void ReplenishJumps();

protected:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UHorizontalBox> CounterBox;

	UPROPERTY()
	TArray<UFloatIndicatorWidget*> FloatIndicators;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UFloatIndicatorWidget> FloatIndicatorClass;

	

	
};
