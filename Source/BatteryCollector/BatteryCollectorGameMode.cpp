// Copyright Epic Games, Inc. All Rights Reserved.

#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ABatteryCollectorGameMode::ABatteryCollectorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	DelayTime = 0.2f;
	DecayAmount = 50.0f;
}

void ABatteryCollectorGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle PowerDecayTimerHandle;

	GetWorld()->GetTimerManager().SetTimer(PowerDecayTimerHandle, this, &ABatteryCollectorGameMode::StartPowerLevelDecay, DelayTime, true);
}

void ABatteryCollectorGameMode::StartPowerLevelDecay()
{
	// Get a reference to our player class
	ABatteryCollectorCharacter* PlayerCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	// check if our power level is greater than zero
	if (PlayerCharacter && PlayerCharacter->GetCurrentPowerLevel() > 0.0f)
	{
		PlayerCharacter->UpdateCurrentPowerLevel(-DecayAmount);
	}
	
	// call the function that updates our power level
}
