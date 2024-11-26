// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpGameController.h"
#include "JumpCharaBase.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AJumpGameController::AJumpGameController() {

}

void AJumpGameController::BeginPlay()
{
	Super::BeginPlay();
	controlledchar = Cast<AJumpCharaBase>(GetPawn());
	if (!controlledchar) {
		return;
	}
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

}

void AJumpGameController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	controlledchar = Cast<AJumpCharaBase>(GetPawn());
}

void AJumpGameController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AJumpGameController::MoveForward);
		EnhancedInputComponent->BindAction(MoveSideAction, ETriggerEvent::Triggered, this, &AJumpGameController::MoveSide);
		EnhancedInputComponent->BindAction(MoveJumpAction, ETriggerEvent::Triggered,this, &AJumpGameController::MoveJump);
	}

	
}


void AJumpGameController::MoveForward(const FInputActionValue& value)
{
	const float inputValue = value.Get<float>();

	if (GetCharacter() != nullptr)
		GetCharacter()->AddMovementInput(FVector::ForwardVector, inputValue);
}

void AJumpGameController::MoveSide(const FInputActionValue& value)
{
	const float inputValue = value.Get<float>();

	if (GetCharacter() != nullptr)
		GetCharacter()->AddMovementInput(FVector::RightVector, inputValue);
}

void AJumpGameController::MoveJump(const FInputActionValue& value)
{
	const float inputValue = value.Get<float>();

	if (GetCharacter() != nullptr)
		GetCharacter()->AddMovementInput(FVector::ZAxisVector, inputValue);
}

