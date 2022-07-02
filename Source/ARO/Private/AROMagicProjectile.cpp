// Copyright zosiu. All Rights Reserved.

#include "AROMagicProjectile.h"

#include "Components/Spherecomponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

AAROMagicProjectile::AAROMagicProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere");
	SphereComponent->SetCollisionProfileName("Projectile");
	RootComponent = SphereComponent;

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>("ParticleSystem");
	ParticleSystemComponent->SetupAttachment(RootComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	ProjectileMovementComponent->InitialSpeed = 1000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bInitialVelocityInLocalSpace = true;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;

	SphereComponent->OnComponentHit.AddDynamic(this, &AAROMagicProjectile::OnHit);
}

void AAROMagicProjectile::OnHit(UPrimitiveComponent* /*HitComp*/, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector /* NormalImpulse */, const FHitResult& /* Hit */)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		Destroy();
	}
}
