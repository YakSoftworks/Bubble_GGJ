

#include "BubPlayer.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include <Engine/DecalActor.h>
#include "BubPlayerController.h"
#include "GameFramework/PlayerState.h"
#include "BubPlayerState.h"


// Sets default values
ABubPlayer::ABubPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BubbleMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BubbleMesh"));
	BubbleMesh->SetupAttachment(RootComponent);

	BubbleSphere = CreateDefaultSubobject<USphereComponent>(TEXT("BubbleSphere"));
	BubbleSphere->SetupAttachment(BubbleMesh);


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	

	

	

}

// Called when the game starts or when spawned
void ABubPlayer::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->SetGroundMovementMode(MOVE_Flying);
	if (ABubPlayerState* playerState = Cast<ABubPlayerState>(UGameplayStatics::GetPlayerState(this, 0)))
	{
		JumpMaxCount = playerState->GetJumpCount();
	}
	



	JumpMaxHoldTime = .8f;/*JumpMaxCount = 10;*/
	

	BlobShadowActor = GetWorld()->SpawnActor<ADecalActor>(GetActorLocation(), FRotator(0, 0, 0));
	//BlobShadowActor.Get()->SetDecalMaterial(DecalMaterial);
	BlobShadowActor.Get()->SetActorScale3D(DecalSize);
	BlobShadowActor->SetDecalMaterial(DecalMaterial);

	if (ABubPlayerController* controller = Cast<ABubPlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
	{
		controller->D_OnJump.AddDynamic(this, &ABubPlayer::PlayerJumped);
	}
	
}

void ABubPlayer::PlayerJumped()
{
	
	GetCharacterMovement()->JumpZVelocity = GetCharacterMovement()->JumpZVelocity * JumpReductionMultiple;	
	/*UE_LOG(LogTemp, Warning, TEXT("%d"), GetCharacterMovement()->JumpZVelocity);*/
	UE_LOG(LogTemp, Warning, TEXT("The float value is: %f"), GetCharacterMovement()->JumpZVelocity);


}

// Called every frame
void ABubPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector End = GetActorLocation();

	End.Z -= 1000;

	FCollisionQueryParams CollisionParams;
	FCollisionResponseParams ResponseParams;

	FHitResult LineTraceHit;
	GetWorld()->LineTraceSingleByChannel(LineTraceHit, GetActorLocation(), End, ECollisionChannel::ECC_Visibility, CollisionParams, ResponseParams);

	if (LineTraceHit.IsValidBlockingHit())
	{
		BlobShadowActor.Get()->SetActorLocation(LineTraceHit.ImpactPoint);
		BlobShadowActor.Get()->SetActorHiddenInGame(false);
		//UE_LOG(LogTemp, Warning, TEXT("HIT"));
	}
	else {
		BlobShadowActor.Get()->SetActorHiddenInGame(true);
	}

	//touched a floor
	if (GetCharacterMovement()->IsMovingOnGround()) 
	{
		
		if (ABubPlayerController* controller = Cast<ABubPlayerController>(UGameplayStatics::GetPlayerController(this, 0)))
		{
			controller->D_OnGrounded.Broadcast();
		}

		GetCharacterMovement()->JumpZVelocity = MaxJumpZVelocity;

		//Touching a new floor
		if (GetCharacterMovement()->CurrentFloor.HitResult.GetActor() != FloorResult.HitResult.GetActor()) {
			//Update the floor we last touched

			FloorResult = GetCharacterMovement()->CurrentFloor;

			JumpMaxHeight = GetActorLocation().Z + JumpMaxDistanceIncrement;

		}
	}

	
	

}

void ABubPlayer::IncrementJumpCount(int increment)
{

	JumpMaxCount += increment;

	if (ABubPlayerState* playerState = Cast<ABubPlayerState>(UGameplayStatics::GetPlayerState(this, 0)))
	{
		playerState->UpdateJumpCount(JumpMaxCount);
	}

}



