// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Runaway.h"
#include "ABAIController.h"
#include "ABCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"

UBTTask_Runaway::UBTTask_Runaway()
{
	NodeName = TEXT("Runaway");
}

EBTNodeResult::Type UBTTask_Runaway::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
		return EBTNodeResult::Failed;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if (nullptr == NavSystem)
		return EBTNodeResult::Failed;

	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(AABAIController::HomePosKey);
	FNavLocation RunPoint;

	if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.0f, RunPoint))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(AABAIController::RunPosKey, RunPoint.Location);
		return EBTNodeResult::Succeeded;
	}
	

	return EBTNodeResult::Failed;
}
