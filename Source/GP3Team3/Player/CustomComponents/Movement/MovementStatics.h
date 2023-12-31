﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class AActor;
class USceneComponent;


struct FMovementStatics
{
	FMovementStatics(const FVector& InStartLocation) :
		StartLocation(InStartLocation) {}
	
	FMovementStatics(AActor* InActor);
	FMovementStatics(USceneComponent* InSceneComponent);

	void AddDelta(const FVector& InDelta);
	void AddGravity(const float GravityToApply) { AccumulatedGravity -= GravityToApply; }

	bool ShouldApplyGravity() const { return !FMath::IsNearlyZero(AccumulatedGravity); }

	FVector GetMovementDelta() const { return MovementDelta; }

	FHitResult Hit;

	FVector FinalLocation = FVector::ZeroVector;

	FVector GetStartLocation() const { return StartLocation; }
	FVector GetGravity() const { return FVector(0.0f, 0.0f, AccumulatedGravity); }
	
private:
	FVector MovementDelta = FVector::ZeroVector;
	FVector StartLocation = FVector::ZeroVector;
	float AccumulatedGravity = 0.0f;
};
