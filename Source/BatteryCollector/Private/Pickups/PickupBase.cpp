// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/PickupBase.h"


// Sets default values
APickupBase::APickupBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bIsActive = true;
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pickup Mesh"));
	RootComponent = PickupMesh;
}

bool APickupBase::IsPickupActive() const
{
	return bIsActive;
}

void APickupBase::SetPickupIsActive(bool NewActiveState)
{
	bIsActive = NewActiveState;
}

// Called when the game starts or when spawned
void APickupBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APickupBase::OnPickupCollected_Implementation()
{
	const FString DebugString = GetName();

	UE_LOG(LogTemp, Warning, TEXT("We Have Picked Up: %s"), *DebugString);
}

