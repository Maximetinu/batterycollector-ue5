// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BatterySpawnerBase.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ABatterySpawnerBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABatterySpawnerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawner")
	class UBoxComponent* SpawnVolume;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category="Spawner")
};
