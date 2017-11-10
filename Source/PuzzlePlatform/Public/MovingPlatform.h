// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORM_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:

	AMovingPlatform();

	void AddActiveTrigger();
	void RemoveActiveTrigger();

protected:

	virtual void BeginPlay() override;	

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:

	UPROPERTY(EditAnywhere, Category = "Setup")
	float Speed = 20.0f;

	UPROPERTY(EditAnywhere, Category = "Setup", Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	FVector GlobalTargetLocation;

	FVector GlobalStartLocation;
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	int ActiveTriggers = 1;

};
