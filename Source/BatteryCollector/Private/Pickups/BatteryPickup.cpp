// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/BatteryPickup.h"


// Sets default values
ABatteryPickup::ABatteryPickup()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupMesh->SetSimulatePhysics(true);

	ChargeAmount = 100.0f;
}

// Called when the game starts or when spawned
void ABatteryPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABatteryPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABatteryPickup::OnPickupCollected_Implementation()
{
	Super::OnPickupCollected_Implementation();

	Destroy();
}

float ABatteryPickup::GetBatteryChargeAmount()
{
	return  ChargeAmount;
}

