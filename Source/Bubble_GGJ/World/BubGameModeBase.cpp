// Fill out your copyright notice in the Description page of Project Settings.


#include "BubGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

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

	UGameplayStatics::SetGamePaused(this, true);
	

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

	UGameplayStatics::SetGamePaused(this, false);
	
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
