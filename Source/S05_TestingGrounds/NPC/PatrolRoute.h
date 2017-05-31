// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PatrolRoute.generated.h"

/**
* A "route card" to help AI choose their next waypoint
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class S05_TESTINGGROUNDS_API UPatrolRoute : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray<AActor*> GetPatrolPoints() const; // This is a Getter (GET): Get Patrol points from TArray OF AActor
	
private:
	//	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	UPROPERTY(EditAnywhere, Category = "Patrol Route")
		TArray<AActor*> PatrolPoints;

};