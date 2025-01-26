// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BubPauseMenuWidget.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class BUBBLE_GGJ_API UBubPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativePreConstruct() override;

public:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ResumeButton;

	UFUNCTION()
	void OnResumeButtonClicked();

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> QuitButton;

	UFUNCTION()
	void OnQuitButtonClicked();

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	FName MainMenuLevelName = "MainMenu";



	
};
