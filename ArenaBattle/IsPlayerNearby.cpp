// Fill out your copyright notice in the Description page of Project Settings.

#include "IsPlayerNearby.h"
#include "ABAIController.h"
#include "ABCharacter.h"
#include "ABCharacterStatComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UIsPlayerNearby::UIsPlayerNearby()
{
	NodeName = TEXT("IsPlayerNearBy");
}

bool UIsPlayerNearby::CalculateRawConditionValue(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory) const
{
	bool bResult = false;

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();

	FVector character = Cast<AABCharacter>(OwnerComp.GetAIOwner())->GetActorLocation();
	FVector Player = Cast<AABCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AABAIController::TargetKey))->GetActorLocation();

	if (FVector::Distance(character, Player) < 100.0f)
	{
		bResult = true;
	}
	else {
		bResult = false;
	}
	return bResult;
}
