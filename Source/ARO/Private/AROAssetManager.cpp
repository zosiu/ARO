// Copyright zosiu. All Rights Reserved.

#include "AROAssetManager.h"

#include "ARONativeGameplayTags.h"

UAROAssetManager& UAROAssetManager::Get()
{
	check(GEngine);
	return *Cast<UAROAssetManager>(GEngine->AssetManager);
}

void UAROAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FARONativeGameplayTags::Initialize();
}
