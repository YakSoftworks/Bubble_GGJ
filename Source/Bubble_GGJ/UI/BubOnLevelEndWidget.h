// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BubOnLevelEndWidget.generated.h"


class UButton;
/**
 * 
 */
UCLASS()
class BUBBLE_GGJ_API UBubOnLevelEndWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativePreConstruct() override;

public:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ContinueButton;

	UFUNCTION()
	void OnContinueButtonClicked();

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> QuitButton;

	UFUNCTION()
	void OnQuitButtonClicked();

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	FName MainMenuLevelName = "MainMenu";

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	FName NextLevelName = "MainMenu";
	
};
