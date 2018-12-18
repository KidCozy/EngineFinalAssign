// Fill out your copyright notice in the Description page of Project Settings.

#include "BTDecorator_IsHealthLow.h"
#include "ABAIController.h"
#include "ABCharacter.h"
#include "ABCharacterStatComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsHealthLow::UBTDecorator_IsHealthLow()
{
	NodeName = TEXT("IsHealthLow");
}

bool UBTDecorator_IsHealthLow::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
		return false;

	auto Target = Cast<AABCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AABAIController::TargetKey));
	if (nullptr == Target)
		return false;

	bResult = (Cast<AABCharacter>(OwnerComp.GetAIOwner()->GetPawn())->CharacterStat->GetHPRatio() <= 0.3f);
	return bResult;
}
