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

		UE_LOG(LogTemp, Warning, TEXT("Collision Condition"));

		if (dropComponent == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("null drop"));
		}

		if (this->WeaponComponent == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("null weapon"));
		}

		if (dropComponent != nullptr && this->WeaponComponent != nullptr)
		{
			switch (dropComponent->GetDropType())
			{
			case EDropTypes::Small_Bullet:
				UE_LOG(LogTemp, Warning, TEXT("Smol Bullet"));
				this->WeaponComponent->SetBulletSizeModifier(0.6f);
				break;
			case EDropTypes::Medium_Bullet:
				UE_LOG(LogTemp, Warning, TEXT("Med Bullet"));
				this->WeaponComponent->SetBulletSizeModifier(1.0f);
				break;
			case EDropTypes::Large_Bullet:
				UE_LOG(LogTemp, Warning, TEXT("Lorg Bullet"));
				this->WeaponComponent->SetBulletSizeModifier(1.5f);
				break;
			case EDropTypes::XL_Bullet:
				UE_LOG(LogTemp, Warning, TEXT("XL Bullet"));
				this->WeaponComponent->SetBulletSizeModifier(2.0f);
				break;
			default:
				break;
			}

			UE_LOG(LogTemp, Warning, TEXT("Drop: %s"), *UEnum::GetDisplayValueAsText(dropComponent->GetDropType()).ToString());
		}
	}
}