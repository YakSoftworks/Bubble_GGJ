// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BubMainMenuWidget.generated.h"

class UButton;
class UVerticalBox;
/**
 * 
 */
UCLASS()
class BUBBLE_GGJ_API UBubMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	void NativeConstruct() override;

protected:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> StartButton;

	UFUNCTION()
	void OnStartButtonClicked();

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> CreditsButton;

	UFUNCTION()
	void OnCreditsButtonClicked();

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> QuitButton;

	UFUNCTION()
	void OnQuitButtonClicked();

	UPROPERTY(EditDefaultsOnly, Category = "Game")
	FName LevelToOpen;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UVerticalBox> CreditsBox;


	
};
