// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawners/BatterySpawnerBase.h"
#include "BatteryCollector/Public/Pickups/PickupBase.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ABatterySpawnerBase::ABatterySpawnerBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawner"));
}

// Called when the game starts or when spawned
void ABatterySpawnerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABatterySpawnerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FVector ABatterySpawnerBase::GetRandomSpawnPoint()
{
	const FVector SpawnOrigin = SpawnVolume->Bounds.Origin;
	const FVector SpawnLimits = SpawnVolume->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnLimits);
}

void ABatterySpawnerBase::SpawnBatteryActor()
{
	// Makes sure we have an actor to spawn
	if (!ActorToSpawn) { return; }

	FRotator RandomRotation;
	RandomRotation.Yaw = FMath::RandRange(1, 3) * 360.0f;
	RandomRotation.Pitch = FMath::RandRange(1, 3) * 360.0f;
	RandomRotation.Roll = FMath::RandRange(1, 3) * 360.0f;
	
	// setup the spawn parameters
	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.Instigator = GetInstigator();
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	
	// spawn actor
	if (!GetWorld()) { return; }

	// APickupBase* ActorSpawned =
	GetWorld()->SpawnActor<APickupBase>(ActorToSpawn, GetRandomSpawnPoint(), RandomRotation, Params);
}

