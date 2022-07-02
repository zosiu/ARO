// Copyright zosiu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"

#include "AROCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class ARO_API AAROCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAROCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;

	UFUNCTION(BlueprintCallable)
	void MoveForward(float ScaleValue);

	UFUNCTION(BlueprintCallable)
	void Turn(float Val);
};
