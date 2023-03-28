// Fill out your copyright notice in the Description page of Project Settings.


#include "PC2_Pawn.h"
#include "TP_WeaponComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CapsuleComponent.h"
#include "DropBehaviorActorComponent.h"

APC2_Pawn::APC2_Pawn()
{
	this->WeaponComponent = nullptr;
	this->PawnCapsuleComponent = nullptr;
}

void APC2_Pawn::BeginPlay()
{
	Super::BeginPlay();

	this->PawnCapsuleComponent = FindComponentByClass<UCapsuleComponent>();
	if (this->PawnCapsuleComponent != nullptr)
	{
		this->PawnCapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &APC2_Pawn::OnCapsuleBeginOverlap);
	}

	if (this->WeaponComponent != nullptr)
	{
		this->WeaponComponent->SetBulletSizeModifier(0.6f);
	}
}

void APC2_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APC2_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APC2_Pawn::OnCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp != nullptr && OtherActor != nullptr && OtherComp->GetCollisionObjectType() == DROP_COLLISION_CHANNEL)
	{
		UDropBehaviorActorComponent* dropComponent = OtherActor->FindComponentByClass<UDropBehaviorActorComponent>();
		if (dropComponent != nullptr && this->WeaponComponent != nullptr)
		{
			switch (dropComponent->GetDropType())
			{
			case EDropTypes::Small_Bullet:
				this->WeaponComponent->SetBulletSizeModifier(0.2f);
				break;
			case EDropTypes::Medium_Bullet:
				this->WeaponComponent->SetBulletSizeModifier(0.6f);
				break;
			case EDropTypes::Large_Bullet:
				this->WeaponComponent->SetBulletSizeModifier(1.4f);
				break;
			case EDropTypes::XL_Bullet:
				this->WeaponComponent->SetBulletSizeModifier(2.0f);
				break;
			default:
				break;
			}
		}
	}
}