// Copyright zosiu. All Rights Reserved.

#include "AROCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AAROCharacter::AAROCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void AAROCharacter::MoveForward(float ScaleValue)
{
	AddMovementInput(GetActorForwardVector(), ScaleValue);
}

void AAROCharacter::Turn(float Val)
{
	AddControllerYawInput(Val);
}
