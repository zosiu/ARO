// Copyright zosiu. All Rights Reserved.

#include "AROExplosiveBarrel.h"

#include "AROMagicProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

AAROExplosiveBarrel::AAROExplosiveBarrel()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	StaticMeshComponent->SetSimulatePhysics(true);
	StaticMeshComponent->SetCollisionProfileName("PhysicsActor");
	RootComponent = StaticMeshComponent;

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForceComponent->Radius = 600.0f;
	RadialForceComponent->ImpulseStrength = 1200.0f;
	RadialForceComponent->bImpulseVelChange = true;
	RadialForceComponent->SetupAttachment(RootComponent);

	StaticMeshComponent->OnComponentHit.AddDynamic(this, &AAROExplosiveBarrel::OnHit);
}

void AAROExplosiveBarrel::OnHit(UPrimitiveComponent* /*HitComp*/, AActor* OtherActor, UPrimitiveComponent* /*OtherComp*/, FVector /*NormalImpulse*/, const FHitResult& Hit)
{
	if (OtherActor->IsA(AAROMagicProjectile::StaticClass()))
	{
		if (ExplosionEmitterTemplate != nullptr)
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEmitterTemplate, Hit.ImpactPoint, Hit.ImpactNormal.Rotation(), true);
		}

		RadialForceComponent->FireImpulse();

		Destroy();
	}
}
