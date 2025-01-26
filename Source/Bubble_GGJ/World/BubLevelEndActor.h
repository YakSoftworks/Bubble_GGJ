// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BubLevelEndActor.generated.h"

class USphereComponent;
class UWidgetComponent;

UCLASS()
class BUBBLE_GGJ_API ABubLevelEndActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABubLevelEndActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<USphereComponent> TouchSphere;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<UWidgetComponent> FlagMarkerComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	float TimeBeforeMarkerShows = 60.f;

	UPROPERTY()
	float TimeInCurrentLevel = 0.f;

	UFUNCTION()
	void OnTouchSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
