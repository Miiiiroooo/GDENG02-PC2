// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DropBehaviorActorComponent.generated.h"


UENUM()
enum class EDropTypes : uint8
{
	Unknown					UMETA(DisplayName = "Unknown"),
	Small_Bullet			UMETA(DisplayName = "Small Bullet"),
	Medium_Bullet			UMETA(DisplayName = "Medium Bullet"),
	Large_Bullet			UMETA(DisplayName = "Large Bullet"),
	XL_Bullet				UMETA(DisplayName = "XL Bullet"),
	Random					UMETA(DisplayName = "Random"),
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GDENG02_PC2_API UDropBehaviorActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDropBehaviorActorComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

private: 
	UPROPERTY(EditAnywhere) TArray<AActor*> DropList;
	UPROPERTY(EditAnywhere) EDropTypes DropType;
};
