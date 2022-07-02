// Copyright zosiu. All Rights Reserved.

#include "AROCharacter.h"

#include "AROEnhancedInputComponent.h"
#include "ARONativeGameplayTags.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AAROCharacter::AAROCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	TurnRate = 45.0f;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent);

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void AAROCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	auto EnhancedInputComponent = Cast<UAROEnhancedInputComponent>(PlayerInputComponent);
	check(EnhancedInputComponent);

	const FARONativeGameplayTags& GameplayTags = FARONativeGameplayTags::Get();
	EnhancedInputComponent->BindActionByTag(InputConfig, GameplayTags.InputTag_Move, ETriggerEvent::Triggered, this, &AAROCharacter::Input_Move);
	EnhancedInputComponent->BindActionByTag(InputConfig, GameplayTags.InputTag_Look_Mouse, ETriggerEvent::Triggered, this, &AAROCharacter::Input_Look);
	EnhancedInputComponent->BindActionByTag(InputConfig, GameplayTags.InputTag_Look_Stick, ETriggerEvent::Triggered, this, &AAROCharacter::Input_Look);
	EnhancedInputComponent->BindActionByTag(InputConfig, GameplayTags.InputTag_Fire, ETriggerEvent::Triggered, this, &AAROCharacter::Input_Fire);
}

void AAROCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * TurnRate * GetWorld()->GetDeltaSeconds());
}

void AAROCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * TurnRate * GetWorld()->GetDeltaSeconds());
}

void AAROCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MoveValue = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0.0f, GetControlRotation().Yaw, 0.0f);

	if (MoveValue.X != 0.0f)
	{
		const FVector MovementDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(MovementDirection, MoveValue.X);
	}

	if (MoveValue.Y != 0.0f)
	{
		const FVector MovementDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(MovementDirection, MoveValue.Y);
	}
}

void AAROCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	if (Controller != nullptr)
	{
		const FVector2D LookValue = InputActionValue.Get<FVector2D>();

		if (LookValue.X != 0.0f)
		{
			TurnAtRate(LookValue.X);
		}

		if (LookValue.Y != 0.0f)
		{
			LookUpAtRate(LookValue.Y);
		}
	}
}

void AAROCharacter::Input_Fire(const FInputActionValue& /* InputActionValue */)
{
	if (ProjectileClass)
	{
		FTransform SpawnTransform(GetActorRotation(), GetMesh()->GetSocketLocation("Muzzle_01"));
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTransform, SpawnParams);
	}
}
