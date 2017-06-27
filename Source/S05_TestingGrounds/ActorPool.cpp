// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "ActorPool.h"


// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


AActor* UActorPool::Checkout()
{
	
	if (Pool.Num() == 0)
	{
		return nullptr;
	}
	return Pool.Pop();
}

void UActorPool::Return(AActor* ActorToReturn)
{
	Add(ActorToReturn);


	/*if (ActorToReturn == nullptr)
	{
	UE_LOG(LogTemp, Warning, TEXT("[%s] Returned null actor."),*GetName());
	return;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor returned: {%s}."), *GetName(), *ActorToReturn->GetName());	
*/
}

void UActorPool::Add(AActor* ActorToAdd)
{
	Pool.Push(ActorToAdd);
	



	/*if (ActorToAdd == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] Added null actor."), *GetName());
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Actor Added: {%s}."), *GetName(), *ActorToAdd->GetName());*/
}
