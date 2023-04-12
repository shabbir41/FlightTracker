// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <glm/vec3.hpp>
#include "CesiumGeospatial/Ellipsoid.h"
#include "CesiumGeospatial/Cartographic.h"
#include "Components/SplineComponent.h"
#include "CesiumGeoreference.h"
#include "Engine/DataTable.h"
#include "PlaneTrack.generated.h"

USTRUCT(BlueprintType)
struct FAircraftRawData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FAircraftRawData()
		: Longitude(0.0)
		, Latitude(0.0)
		, Height(0.0)
	{}

	UPROPERTY(EditAnywhere, Category = "FlightTracker")
		double Longitude;
	UPROPERTY(EditAnywhere, Category = "FlightTracker")
		double Latitude;
	UPROPERTY(EditAnywhere, Category = "FlightTracker")
		double Height;
};


UCLASS()
class FLIGHTTRACKER_API APlaneTrack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlaneTrack();

	//Spline variable to represent the plane track
	UPROPERTY(BlueprintReadOnly, Category = "FlightTracker")
		USplineComponent* SplineTrack;

	// Cesium class tha contain many usefull functions for coordinate conversions
	UPROPERTY(EditAnywhere, Category = "FlightTracker")
		ACesiumGeoreference* CesiumGeoreference;

	// An UE DataTable to store the raw flight data
	UPROPERTY(EditAnywhere, Category = "FlightTracker")
		UDataTable* AircraftsRawDataTable;

	UFUNCTION(BlueprintCallable, Category = "FlightTracker")
		void LoadSplineTrackPoints();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
