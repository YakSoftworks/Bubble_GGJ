// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BubPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class BUBBLE_GGJ_API ABubPlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	void UpdateJumpCount(int value);
	FORCEINLINE int32 GetJumpCount() const { return PlayerJumpCount; }

protected:

	int32 PlayerJumpCount = 2;
	
};
