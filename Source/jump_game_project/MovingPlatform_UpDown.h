// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform_UpDown.generated.h"

UCLASS()
class JUMP_GAME_PROJECT_API AMovingPlatform_UpDown : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform_UpDown();
	UPROPERTY(EditAnywhere)
	FVector MyVector;
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY()
	int32 direction;
	UPROPERTY()
	int32 second;
	UPROPERTY()
	int32 speed;

};
