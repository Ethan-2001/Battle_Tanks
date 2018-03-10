// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track Is Used To Set Maximum Driving Force, And Apply Forces To The Tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLE_TANKS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Sets A Throttle Between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	// Max Force Per Track In Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 40000000; // Assume 40 Ton Tank, And 1g Acceleration
	
};
