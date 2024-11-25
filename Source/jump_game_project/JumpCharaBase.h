// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "JumpCharaBase.generated.h"

UCLASS()
class JUMP_GAME_PROJECT_API AJumpCharaBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJumpCharaBase();
	UPROPERTY(EditAnywhere,Category="Input")
	UInputMappingContext* DefaultMappingContext;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* fowardAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* sideAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* jumpAction;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void move(const FInputActionInstance& instance);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
