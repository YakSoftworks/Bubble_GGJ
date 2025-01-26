// Fill out your copyright notice in the Description page of Project Settings.


#include "BubPlayerUI.h"
#include "Bubble_GGJ/Player/BubPlayerState.h"
#include "FloatCounterWidget.h"
#include <Kismet/GameplayStatics.h>
#include "Bubble_GGJ/Player/BubPlayerController.h"

void UBubPlayerUI::NativeConstruct()
{

	Super::NativeConstruct();

	//Get the player State
	if (ABubPlayerState* playerState = Cast<ABubPlayerState>(UGameplayStatics::GetPlayerState(GetWorld(), 0)))
	{
		for (int i = 0; i < playerState->GetJumpCount(); i++)
		{
			FloatCounterWidget->AddOneToCounter();
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("UI Settled"));

	if (ABubPlayerController* playerController = Cast<ABubPlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
	{
		playerController->D_OnJump.AddDynamic(this, &UBubPlayerUI::OnJump);
		playerController->D_OnGrounded.AddDynamic(this, &UBubPlayerUI::OnGrounded);
	}
	UE_LOG(LogTemp, Warning, TEXT("Delegates Bound"));




}

void UBubPlayerUI::OnJump()
{
	FloatCounterWidget->UseJump();
}

void UBubPlayerUI::OnGrounded()
{
	FloatCounterWidget->ReplenishJumps();
}
