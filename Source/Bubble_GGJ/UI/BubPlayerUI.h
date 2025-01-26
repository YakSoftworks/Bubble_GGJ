// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BubPlayerUI.generated.h"

class UFloatCounterWidget;
/**
 * 
 */
UCLASS()
class BUBBLE_GGJ_API UBubPlayerUI : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

protected:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UFloatCounterWidget> FloatCounterWidget;

	UFUNCTION()
	void OnJump();

	UFUNCTION()
	void OnGrounded();
	
};
