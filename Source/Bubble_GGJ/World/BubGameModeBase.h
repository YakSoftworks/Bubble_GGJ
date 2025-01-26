// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BubGameModeBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPause_Delegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnResume_Delegate);

/**
 * 
 */
UCLASS()
class BUBBLE_GGJ_API ABubGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	ABubGameModeBase();

	virtual void BeginPlay() override;

public:

	UPROPERTY()
	FOnPause_Delegate OnPause;

	UPROPERTY()
	FOnResume_Delegate OnResume;


	UFUNCTION()
	void PauseGame();

	UFUNCTION()
	void ResumeGame();

	void TogglePause();

	void EndLevel();

	
protected:

	UPROPERTY()
	bool bIsPaused = false;

	UPROPERTY(EditDefaultsOnly, Category = "PauseUI")
	TObjectPtr<UUserWidget> PauseMenuWidget;

	UPROPERTY(EditDefaultsOnly, Category = "PauseUI")
	TSubclassOf<UUserWidget> PauseMenuWidgetClass;


	UPROPERTY(EditDefaultsOnly, Category = "PauseUI")
	TObjectPtr<UUserWidget> EndLevelWidget;

	UPROPERTY(EditDefaultsOnly, Category = "PauseUI")
	TSubclassOf<UUserWidget> EndLevelWidgetClass;








	
};
