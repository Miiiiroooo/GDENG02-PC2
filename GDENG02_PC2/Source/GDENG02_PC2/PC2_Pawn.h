// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDENG02_PC2Character.h"
#include "PC2_Pawn.generated.h"


class UTP_WeaponComponent;
class UCapsuleComponent;


UCLASS()
class GDENG02_PC2_API APC2_Pawn : public AGDENG02_PC2Character
{
	GENERATED_BODY()
	
public:
	APC2_Pawn();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void OnCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:
	UPROPERTY() UTP_WeaponComponent* WeaponComponent;
	UPROPERTY() UCapsuleComponent* PawnCapsuleComponent;
};
