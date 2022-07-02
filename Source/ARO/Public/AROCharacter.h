// Copyright zosiu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Character.h"
#include "EnhancedInput/Public/InputActionValue.h"

#include "AROCharacter.generated.h"

class UAROInputConfig;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class ARO_API AAROCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	float TurnRate;

	AAROCharacter();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UAROInputConfig* InputConfig;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);
};
