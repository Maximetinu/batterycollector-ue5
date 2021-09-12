// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupBase.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API APickupBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APickupBase();

	// Gets the value of whether or not this pickup is active
	UFUNCTION(BlueprintPure, Category="Pickup")
	bool IsPickupActive() const;

	UFUNCTION(BlueprintCallable, Category="Pickup")
	void SetPickupIsActive(bool NewActiveState);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	bool bIsActive;

	UPROPERTY(EditDefaultsOnly, Category="Components")
	UStaticMeshComponent* PickupMesh;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
