// Copyright zosiu. All Rights Reserved.

#include "ARONativeGameplayTags.h"

#include "Engine/EngineTypes.h"
#include "GameplayTagsManager.h"

FARONativeGameplayTags FARONativeGameplayTags::GameplayTags;

void FARONativeGameplayTags::Initialize()
{
	UGameplayTagsManager& GameplayTagsManager = UGameplayTagsManager::Get();

	GameplayTags.AddAllTags(GameplayTagsManager);

	GameplayTagsManager.DoneAddingNativeTags();
}

void FARONativeGameplayTags::AddAllTags(UGameplayTagsManager& Manager)
{
	InputTag_Move = AddTag("InputTag.Move", "Move input.");
	InputTag_Look_Mouse = AddTag("InputTag.Look.Mouse", "Look input (mouse).");
	InputTag_Look_Stick = AddTag("InputTag.Look.Stick", "Look input (stick).");
	InputTag_Fire = AddTag("InputTag.Fire", "Fire input.");
	InputTag_Jump = AddTag("InputTag.Jump", "Jump input.");
}

FGameplayTag FARONativeGameplayTags::AddTag(const ANSICHAR* TagName, const ANSICHAR* TagComment)
{
	return UGameplayTagsManager::Get().AddNativeGameplayTag(FName(TagName), FString(TEXT("(Native) ")) + FString(TagComment));
}
