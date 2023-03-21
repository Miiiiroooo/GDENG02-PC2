// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDENG02_PC2Character.h"
#include "PC2_Pawn.generated.h"

/**
 * 
 */
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

};
