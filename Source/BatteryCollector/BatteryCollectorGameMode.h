// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryCollectorGameMode.generated.h"

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();


protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float DelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float DecayAmount;

	virtual void BeginPlay() override;

	void StartPowerLevelDecay();
};



