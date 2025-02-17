
#include "BubPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "BubPlayer.h"
#include "InputActionValue.h"
#include "Bubble_GGJ/UI/BubPlayerUI.h"
#include "Kismet/GameplayStatics.h"
#include "Bubble_GGJ/World/BubGameModeBase.h"



void ABubPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (ABubPlayer* player = Cast<ABubPlayer>(InPawn))
	{
		PossessedBubble = player;
	}

}

// Called to bind functionality to input
void ABubPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputContext, 0);
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{

		//Bind Move Action
		/*EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABubPlayerController::MoveEvent);*/
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABubPlayerController::MoveEvent);


		//Bind Jump Action
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ABubPlayerController::JumpEvent);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ABubPlayerController::StopJumpingEvent);

		//Look
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABubPlayerController::LookEvent);

		//Pause
		EnhancedInputComponent->BindAction(TogglePauseAction, ETriggerEvent::Started, this, &ABubPlayerController::TogglePauseEvent);

	}



}

void ABubPlayerController::MoveEvent(const FInputActionValue& value)
{
	if (!PossessedBubble)
	{
		return;
	}

	FVector2D MoveInput = value.Get<FVector2D>();

	const FRotator Rotation = GetControlRotation();

	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	PossessedBubble->AddMovementInput(ForwardVector, MoveInput.Y);
	PossessedBubble->AddMovementInput(RightVector, MoveInput.X);

	//UE_LOG(LogTemp, Warning, TEXT("%s", MoveInput.ToString()));

}

void ABubPlayerController::JumpEvent(const FInputActionValue& value)
{

	if (!PossessedBubble)
	{
		return;
	}
	PossessedBubble->Jump();

	D_OnJump.Broadcast();

	UE_LOG(LogTemp, Warning, TEXT("Jump Triggered"));


}

void ABubPlayerController::StopJumpingEvent(const FInputActionValue& value)
{
	if (!PossessedBubble)
	{
		return;
	}
	PossessedBubble->StopJumping();

	UE_LOG(LogTemp, Warning, TEXT("Jump Ended"));
}

void ABubPlayerController::LookEvent(const FInputActionValue& value)
{

	FVector2D LookInput = value.Get<FVector2D>();

	if (!PossessedBubble)
	{
		return;
	}

	ControlRotation.Yaw += (LookInput.X*HorizontalLookSpeed);
	ControlRotation.Pitch += (LookInput.Y*VerticalLookSpeed);

}

void ABubPlayerController::TogglePauseEvent(const FInputActionValue& value)
{
	if (ABubGameModeBase* GM = Cast<ABubGameModeBase>(UGameplayStatics::GetGameMode(this)))

	{
		GM->TogglePause();
	}

}

void ABubPlayerController::BeginPlay()
{
	Super::BeginPlay();
	PlayerUI = CreateWidget<UUserWidget>(this, PlayerUIClass);
	PlayerUI->AddToViewport();
	UE_LOG(LogTemp, Warning, TEXT("Player UI Created"));

	if (ABubGameModeBase* GM = Cast<ABubGameModeBase>(UGameplayStatics::GetGameMode(this)))
	{
		GM->OnPause.AddDynamic(this, &ABubPlayerController::OnPause);
		GM->OnResume.AddDynamic(this, &ABubPlayerController::OnResume);
	}

	OnResume();
}

void ABubPlayerController::OnPause()
{
	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
}

void ABubPlayerController::OnResume()
{
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}
