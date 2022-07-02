// Copyright zosiu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "AROInputConfig.h"
#include "GameplayTagContainer.h"

#include "AROEnhancedInputComponent.generated.h"

UCLASS()
class ARO_API UAROEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template <class UserClass, typename FuncType>
	void BindActionByTag(const UAROInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func);
};

template <class UserClass, typename FuncType>
void UAROEnhancedInputComponent::BindActionByTag(const UAROInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func)
{
	check(InputConfig);
	if (const UInputAction* InputAction = InputConfig->FindInputActionForTag(InputTag))
	{
		BindAction(InputAction, TriggerEvent, Object, Func);
	}
}
