// Copyright zosiu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameplayTagContainer.h"

class UGameplayTagsManager;

struct FARONativeGameplayTags
{
public:
	static const FARONativeGameplayTags& Get() { return GameplayTags; }

	static void Initialize();

	// Input tags
	FGameplayTag InputTag_Move;
	FGameplayTag InputTag_Look_Mouse;
	FGameplayTag InputTag_Look_Stick;

protected:
	void AddAllTags(UGameplayTagsManager& Manager);
	FGameplayTag AddTag(const ANSICHAR* TagName, const ANSICHAR* TagComment);

private:
	static FARONativeGameplayTags GameplayTags;
};
