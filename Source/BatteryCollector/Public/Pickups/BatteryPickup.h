// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupBase.h"
#include "GameFramework/Actor.h"
#include "BatteryPickup.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickupBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABatteryPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
