// Fill out your copyright notice in the Description page of Project Settings.


#include "BubPauseMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Bubble_GGJ/World/BubGameModeBase.h"

void UBubPauseMenuWidget::NativePreConstruct()
{
	ResumeButton->OnClicked.AddDynamic(this, &UBubPauseMenuWidget::OnResumeButtonClicked);
	QuitButton->OnClicked.AddDynamic(this, &UBubPauseMenuWidget::OnQuitButtonClicked);
}

void UBubPauseMenuWidget::OnResumeButtonClicked()
{

	if (ABubGameModeBase* GM = Cast<ABubGameModeBase>(UGameplayStatics::GetGameMode(this))) {
		GM->ResumeGame();
	}

}

void UBubPauseMenuWidget::OnQuitButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), MainMenuLevelName);
}
