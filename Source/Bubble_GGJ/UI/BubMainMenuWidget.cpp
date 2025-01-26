// Fill out your copyright notice in the Description page of Project Settings.


#include "BubMainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Components/VerticalBox.h"

void UBubMainMenuWidget::NativeConstruct()
{

	//StartButton->OnPressed.AddDynamic(this, &UBubMainMenuWidget::OnStartButtonClicked);
	////CreditsButton->OnClicked.AddDynamic(this, &UBubMainMenuWidget::OnCreditsButtonClicked);
	//QuitButton->OnPressed.AddDynamic(this, &UBubMainMenuWidget::OnQuitButtonClicked);

	StartButton->OnClicked.AddDynamic(this, &UBubMainMenuWidget::OnStartButtonClicked);
	QuitButton->OnClicked.AddDynamic(this, &UBubMainMenuWidget::OnQuitButtonClicked);

	CreditsBox->SetVisibility(ESlateVisibility::Hidden);

}

void UBubMainMenuWidget::OnStartButtonClicked()
{

	UGameplayStatics::OpenLevel(GetWorld(), LevelToOpen);

}

void UBubMainMenuWidget::OnCreditsButtonClicked()
{

	//Do nothin

}

void UBubMainMenuWidget::OnQuitButtonClicked()
{

	//Quit the game
	FGenericPlatformMisc::RequestExit(false);
}
