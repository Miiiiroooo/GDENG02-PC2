// Fill out your copyright notice in the Description page of Project Settings.


#include "PC2_Pawn.h"
#include "TP_WeaponComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/CapsuleComponent.h"

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
		UE_LOG(LogTemp, Warning, TEXT("capsulke"));
		this->PawnCapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &APC2_Pawn::OnCapsuleBeginOverlap);
	}
	/*UCapsuleComponent* capsule = this->GetCapsuleComponent();
	if (capsule != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("capsulke"));
		capsule->OnComponentBeginOverlap.AddDynamic(this, &APC2_Pawn::OnCapsuleBeginOverlap);
	}*/
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
	UE_LOG(LogTemp, Warning, TEXT("OVERLAP"));
}