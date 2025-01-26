// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BubPlayerController.generated.h"

class UBubPlayerUI;
class UInputMappingContext;
class UInputAction;
class ABubPlayer;
struct FInputActionValue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnJumpDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGroundedDelegate);
/**
 * 
 */
UCLASS()
class BUBBLE_GGJ_API ABubPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY()
	FOnJumpDelegate D_OnJump;

	UPROPERTY()
	FOnGroundedDelegate D_OnGrounded;

protected:

	void OnPossess(APawn* InPawn) override;

	UPROPERTY()
	TObjectPtr<ABubPlayer> PossessedBubble;

#pragma region Inputs

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> InputContext;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float HorizontalLookSpeed = 1.f;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float VerticalLookSpeed = 1.f;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> TogglePauseAction;



#pragma region Input Events

	void MoveEvent(const FInputActionValue& value);

	void JumpEvent(const FInputActionValue& value);

	void StopJumpingEvent(const FInputActionValue& value);

	void LookEvent(const FInputActionValue& value);

	void TogglePauseEvent(const FInputActionValue& value);


#pragma endregion 

#pragma endregion
	
#pragma region UI

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	
	TObjectPtr<UUserWidget> PlayerUI;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UBubPlayerUI> PlayerUIClass;

	void BeginPlay() override;

	UFUNCTION()
	void OnPause();

	UFUNCTION()
	void OnResume();

#pragma endregion

};
