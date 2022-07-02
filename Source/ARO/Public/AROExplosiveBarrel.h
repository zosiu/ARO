// Copyright zosiu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

#include "AROExplosiveBarrel.generated.h"

class UStaticMeshComponent;
class URadialForceComponent;
class UParticleSystem;

UCLASS()
class ARO_API AAROExplosiveBarrel : public AActor
{
	GENERATED_BODY()

public:
	AAROExplosiveBarrel();

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<URadialForceComponent> RadialForceComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UParticleSystem> ExplosionEmitterTemplate;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
