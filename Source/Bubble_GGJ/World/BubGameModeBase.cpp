// Fill out your copyright notice in the Description page of Project Settings.


#include "BubGameModeBase.h"
#include "Blueprint/UserWidget.h"

ABubGameModeBase::ABubGameModeBase()
{
}

void ABubGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	ResumeGame();

	
}


void ABubGameModeBase::PauseGame()
{
	bIsPaused = true;
	UE_LOG(LogTemp, Warning, TEXT("Pausing Game"));
	OnPause.Broadcast();

	if (!PauseMenuWidget)
	{
		PauseMenuWidget = CreateWidget<UUserWidget>(GetWorld(), PauseMenuWidgetClass);
	}
	PauseMenuWidget->AddToViewport();
	

}

void ABubGameModeBase::ResumeGame()
{
	bIsPaused = false;
	UE_LOG(LogTemp, Warning, TEXT("Resuming Game"));
	OnResume.Broadcast();

	if (PauseMenuWidget)
	{
		PauseMenuWidget->RemoveFromParent();
	}
	
}

void ABubGameModeBase::TogglePause()
{
	if (bIsPaused)
	{
		ResumeGame();
	}
	else
	{
		PauseGame();
	}
	bIsPaused = !bIsPaused;
}

void ABubGameModeBase::EndLevel()
{
	bIsPaused = true;
	OnPause.Broadcast();

	if (!EndLevelWidget)
	{
		EndLevelWidget = CreateWidget<UUserWidget>(GetWorld(), EndLevelWidgetClass);
	}
	EndLevelWidget->AddToViewport();


}
