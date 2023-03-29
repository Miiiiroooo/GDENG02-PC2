// Fill out your copyright notice in the Description page of Project Settings.


#include "DropBehaviorActorComponent.h"


UDropBehaviorActorComponent::UDropBehaviorActorComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	this->DropType = EDropTypes::Unknown;
}


void UDropBehaviorActorComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UDropBehaviorActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

EDropTypes UDropBehaviorActorComponent::GetDropType()
{
	return this->DropType;
}

void UDropBehaviorActorComponent::ItemCollected()
{
	parentActor->Destroy();
	this->GetOwner()->Destroy();
}

