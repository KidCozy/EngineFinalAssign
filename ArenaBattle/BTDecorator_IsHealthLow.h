// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsHealthLow.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UBTDecorator_IsHealthLow : public UBTDecorator
{
	GENERATED_BODY()
public:
	UBTDecorator_IsHealthLow();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
