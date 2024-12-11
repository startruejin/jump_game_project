// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform_UpDown.h"
#include "math.h"

// Sets default values
AMovingPlatform_UpDown::AMovingPlatform_UpDown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.5;

}

// Called when the game starts or when spawned
void AMovingPlatform_UpDown::BeginPlay()
{
	Super::BeginPlay();
	MyVector.X = AMovingPlatform_UpDown::GetActorLocation().X;
	MyVector.Y = AMovingPlatform_UpDown::GetActorLocation().Y;
	MyVector.Z = AMovingPlatform_UpDown::GetActorLocation().Z;
	speed = FMath::RandRange(1, 50);
	direction = FMath::RandRange(-1, 1);
	interverl = FMath::RandRange(10, 30);
	
}

// Called every frame
void AMovingPlatform_UpDown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (second < 10) {
		MyVector.Z+= direction * speed;
		second++;
	}
	else {
		direction *= -1;
		second = 0;
	}
	SetActorLocation(MyVector);

}

