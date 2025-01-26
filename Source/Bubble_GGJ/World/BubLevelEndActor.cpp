// Fill out your copyright notice in the Description page of Project Settings.


#include "BubLevelEndActor.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Bubble_GGJ/World/BubGameModeBase.h"

// Sets default values
ABubLevelEndActor::ABubLevelEndActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TouchSphere = CreateDefaultSubobject<USphereComponent>(TEXT("TouchSphere"));
	SetRootComponent(TouchSphere);
	TouchSphere->SetSphereRadius(50.f);

	FlagMarkerComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("FlagMarkerComponent"));
	FlagMarkerComponent->SetupAttachment(TouchSphere);
	


}

// Called when the game starts or when spawned
void ABubLevelEndActor::BeginPlay()
{
	Super::BeginPlay();

	FlagMarkerComponent->SetVisibility(false);

	TouchSphere->OnComponentBeginOverlap.AddDynamic(this, &ABubLevelEndActor::OnTouchSphereOverlap);
	
}

void ABubLevelEndActor::OnTouchSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (ABubGameModeBase* GM = Cast<ABubGameModeBase>(UGameplayStatics::GetGameMode(this)))
	{
		GM->EndLevel();
	}


}

// Called every frame
void ABubLevelEndActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimeInCurrentLevel += DeltaTime;

	if (TimeInCurrentLevel >= TimeBeforeMarkerShows)
	{
		FlagMarkerComponent->SetVisibility(true);
	}

}

