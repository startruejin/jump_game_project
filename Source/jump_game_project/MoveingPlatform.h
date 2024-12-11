// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveingPlatform.generated.h"

UCLASS()
class JUMP_GAME_PROJECT_API AMoveingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMoveingPlatform();
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
	int32 interverl;
	UPROPERTY()
	int32 speed;
};
