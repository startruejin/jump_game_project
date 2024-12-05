// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveingPlatform.h"
#include "math.h"

// Sets default values
AMoveingPlatform::AMoveingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.5;

}

// Called when the game starts or when spawned
void AMoveingPlatform::BeginPlay()
{
	Super::BeginPlay();
	MyVector.X = AMoveingPlatform::GetActorLocation().X;
	MyVector.Y = AMoveingPlatform::GetActorLocation().Y;
	MyVector.Z = AMoveingPlatform::GetActorLocation().Z;
	speed = FMath::RandRange(1, 10);
	direction = FMath::RandRange(-1, 1);

}

// Called every frame
void AMoveingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (second < 10) {
		MyVector.Y += direction*speed;
		second++;
	}
	else {
		direction *= -1;
		second = 0;
	}
	SetActorLocation(MyVector);

}

