// Fill out your copyright notice in the Description page of Project Settings.


#include "BubOnLevelEndWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UBubOnLevelEndWidget::NativePreConstruct()
{


	ContinueButton->OnClicked.AddDynamic(this, &UBubOnLevelEndWidget::OnContinueButtonClicked);
	

	QuitButton->OnClicked.AddDynamic(this, &UBubOnLevelEndWidget::OnQuitButtonClicked);
	


}

void UBubOnLevelEndWidget::OnContinueButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), NextLevelName);
}

void UBubOnLevelEndWidget::OnQuitButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), MainMenuLevelName);
}
