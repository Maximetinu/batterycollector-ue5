// Copyright Epic Games, Inc. All Rights Reserved.

#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "Blueprint/UserWidget.h"
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

	PowerToWinMultiplier = 1.5f;
}

float ABatteryCollectorGameMode::GetPowerAmountToWin() const
{
	return PowerAmountToWin;
}

void ABatteryCollectorGameMode::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle PowerDecayTimerHandle;

	GetWorld()->GetTimerManager().SetTimer(PowerDecayTimerHandle, this, &ABatteryCollectorGameMode::StartPowerLevelDecay, DelayTime, true);

	ABatteryCollectorCharacter* PlayerCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (PlayerCharacter)
	{
		PowerAmountToWin = PlayerCharacter->GetBasePowerLevel() * PowerToWinMultiplier;
	}

	if (MainHUDClass)
	{
		ActiveWidget = CreateWidget<UUserWidget>(GetWorld(), MainHUDClass);
		ActiveWidget->AddToViewport();
	}
}

void ABatteryCollectorGameMode::StartPowerLevelDecay()
{
	// Get a reference to our player class
	ABatteryCollectorCharacter* PlayerCharacter = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	// check if our power level is greater than zero
	if (PlayerCharacter && PlayerCharacter->GetCurrentPowerLevel() > 0.0f)
	{
		// call the function that updates our power level
		PlayerCharacter->UpdateCurrentPowerLevel(-DecayAmount);
	}
}
