// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "PatrolRoute.h"

TArray<AActor*> UPatrolRoute::GetPatrolPoints() const // This is a Getter (GET): Get Patrol points from TArray OF AActor
{
	return PatrolPoints;
}
