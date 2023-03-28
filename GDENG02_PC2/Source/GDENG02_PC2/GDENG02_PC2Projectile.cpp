// Copyright Epic Games, Inc. All Rights Reserved.

#include "GDENG02_PC2Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

AGDENG02_PC2Projectile::AGDENG02_PC2Projectile() 
{
	this->OriginalSphereRadius = 50.0f;
	this->StaticMeshComponent = nullptr;

	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(this->OriginalSphereRadius);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AGDENG02_PC2Projectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 20.0f;
}

void AGDENG02_PC2Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != nullptr)
	{
		

		
		
		SpawnExplode(this->GetActorLocation());
		//Destroy();
	}

	// Only add impulse and destroy projectile if we hit a physics
	/*if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		//OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
	
		Destroy();
	}*/
}

void AGDENG02_PC2Projectile::SetBulletSize(float modifier)
{
	FTransform collisionTransform = this->CollisionComp->GetRelativeTransform();
	collisionTransform.SetScale3D(FVector::OneVector * modifier);
	this->CollisionComp->SetRelativeTransform(collisionTransform);

	/*float newRadius = this->OriginalSphereRadius * modifier;
	this->CollisionComp->SetSphereRadius(newRadius);*/

	/*FTransform meshTransform = this->StaticMeshComponent->GetRelativeTransform();
	meshTransform.SetScale3D(FVector::OneVector * modifier);
	this->StaticMeshComponent->SetRelativeTransform(meshTransform);*/
}