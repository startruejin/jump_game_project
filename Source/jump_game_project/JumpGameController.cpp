// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpGameController.h"
#include "JumpCharaBase.h"
#include "Engine.h"
#include "GameFramework/Character.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Pawn.h"
#include "InputMappingContext.h"
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
		EnhancedInputComponent->BindAction(CameraSide, ETriggerEvent::Triggered, this, &AJumpGameController::MoveCameraSide);
		EnhancedInputComponent->BindAction(CameraUp, ETriggerEvent::Triggered, this, &AJumpGameController::MoveCameraUp);
	}

	
}


void AJumpGameController::MoveForward(const FInputActionValue& value)
{
	const FVector2D inputValue = value.Get<FVector2D>();
	const FRotator Rotation = APlayerController::GetControlRotation();
	const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	if (GetCharacter() != nullptr) {
		GetCharacter()->AddMovementInput(Direction, inputValue.Y);
		
	}

	

}

void AJumpGameController::MoveSide(const FInputActionValue& value)
{
	FVector Direction = UKismetMathLibrary::GetRightVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f));
	const float inputValue = value.Get<float>();

	if (GetCharacter() != nullptr)
		GetCharacter()->AddMovementInput(Direction, inputValue);
}

void AJumpGameController::MoveJump()
{
	if (GetCharacter() != nullptr)
		GetCharacter()->bPressedJump = true;
}

void AJumpGameController::MoveCameraSide(const FInputActionValue& value)
{
	const float inputValue = value.Get<float>();
	if (GetCharacter() != nullptr) {
	GetCharacter()->AddControllerYawInput(inputValue);
	}
}

void AJumpGameController::MoveCameraUp(const FInputActionValue& value)
{
	const float inputValue = value.Get<float>();
	if (GetCharacter() != nullptr) {
		GetCharacter()->AddControllerPitchInput(inputValue);
	}
}

