// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterMovementComponentAsync.h"
#include "BubPlayer.generated.h"

class USphereComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class ADecalActor;
class UMaterial;

UCLASS()
class BUBBLE_GGJ_API ABubPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABubPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USphereComponent> BubbleSphere;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> BubbleMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY()
	TObjectPtr<ADecalActor> BlobShadowActor;

	UPROPERTY(EditDefaultsOnly, Category="DecalShadow")
	FVector DecalSize = FVector(1, 1, 1);

	UPROPERTY(EditDefaultsOnly, Category = "DecalShadow")
	TObjectPtr<UMaterial> DecalMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Jump")
	float JumpMaxHeight;

	UPROPERTY(EditDefaultsOnly, Category = "Jump")
	float JumpMaxDistanceIncrement;

	UPROPERTY()
	FFindFloorResult FloorResult;

	UFUNCTION()
	void PlayerJumped();

	UPROPERTY()
	bool bIsFirstJump = true;

	UPROPERTY(EditDefaultsOnly, Category = "Jump")
	float MaxJumpZVelocity = 100.f;

	UPROPERTY(EditDefaultsOnly, Category = "Jump")
	float JumpReductionMultiple = 0.75f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
