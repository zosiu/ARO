// Copyright zosiu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Engine/AssetManager.h"

#include "AROAssetManager.generated.h"

UCLASS()
class ARO_API UAROAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UAROAssetManager& Get();

protected:
	void StartInitialLoading() override;
};
