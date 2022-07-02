// Copyright zosiu. All Rights Reserved.

#include "AROInputConfig.h"

#include "GameplayTagContainer.h"
#include "EnhancedInput/Public/InputAction.h"

const UInputAction* UAROInputConfig::FindInputActionForTag(const FGameplayTag& InputTag) const
{
	const FAROTaggedInputAction* TaggedInputAction = TaggedInputActions.FindByPredicate([&InputTag](const FAROTaggedInputAction& TaggedInputAction) {
		return TaggedInputAction.InputAction && TaggedInputAction.InputTag == InputTag;
	});

	return TaggedInputAction ? TaggedInputAction->InputAction : nullptr;
}
