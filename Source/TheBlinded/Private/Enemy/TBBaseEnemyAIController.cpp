// The Blinded Game by XTOR Team, All Rights Reserved.

#include "Enemy/TBBaseEnemyAIController.h"
#include "Enemy/TBBaseEnemyCharacter.h"


void ATBBaseEnemyAIController::OnPossess(APawn *InPawn)
{
    Super::OnPossess(InPawn);

    const auto TBCharacter = Cast<ATBBaseEnemyCharacter>(InPawn);
    if (TBCharacter)
    {
        RunBehaviorTree(TBCharacter->BehaviorTreeAsset);

    }
}