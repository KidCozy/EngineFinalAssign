// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "IsPlayerNearby.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UIsPlayerNearby : public UBTDecorator
{
	GENERATED_BODY()
public:
	UIsPlayerNearby();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
