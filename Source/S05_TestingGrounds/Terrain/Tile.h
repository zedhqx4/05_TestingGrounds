// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Tile.generated.h"

USTRUCT()
struct FSpawnPosition
{
	GENERATED_USTRUCT_BODY()

	FVector Location;
	float Rotation;
	float Scale;

};

class UActorPool;

UCLASS()
class S05_TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Spawining")
	FVector MinExtend;

	UPROPERTY(EditDefaultsOnly, Category = "Spawining")
	FVector MaxExtend;

	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	FVector NavigationBoundsOffset;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500, float MinScale = 1, float MaxScale = 1);
	
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void PlaceAiPawns(TSubclassOf<APawn> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500);

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* Pool);

private:

	void PositionNavMeshBoundsVolume();

	TArray<FSpawnPosition> RandomSpawnPositions(int MinSpawn, int MaxSpawn, float MinScale, float MaxScale, float Radius);

	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	template<class T>
	void RandomlyPlacedActors(TSubclassOf<T> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500, float MinScale = 1, float MaxScale = 1);

	void PlaceActor(TSubclassOf<AActor> ToSpawn, FSpawnPosition& SpawnPosition);

	void PlaceActor(TSubclassOf<APawn> ToSpawn, FSpawnPosition SpawnPosition);

	bool CanSpawnAtLocation(FVector Location, float Radius);

	UActorPool* Pool;

	AActor* NavMeshBoundsVolume;

};
