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

	UFUNCTION(BlueprintPure)
	float GetPowerAmountToWin() const;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float DelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float DecayAmount;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float PowerAmountToWin;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	float PowerToWinMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Power")
	TSubclassOf<class UUserWidget> MainHUDClass;

	UPROPERTY() // To subscribe it to garbage collector
	class UUserWidget* ActiveWidget;
	
	virtual void BeginPlay() override;

	void StartPowerLevelDecay();
};



