// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FloatIndicatorWidget.generated.h"

class UImage;
class UVerticalBox;
/**
 * 
 */
UCLASS()
class BUBBLE_GGJ_API UFloatIndicatorWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	void SetupWidget(bool IsUp);

	//Bool for indicating if the icon is up or down
	bool bIsUp = true;

	//Bool for indicating if the jump has been used or not
	bool bIsUsed = false;

	void UseFloat();

	void ReplenishFloat();

protected:

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UImage> FloatIcon;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UVerticalBox> FloatBox;

	UPROPERTY(EditAnywhere)
	FColor FloatIconUnusedColor;

	UPROPERTY(EditAnywhere)
	FColor FloatIconUsedColor;

};
