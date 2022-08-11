// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "AIController.h"
#include "CoreMinimal.h"
#include "TBBaseEnemyAIController.generated.h"

UCLASS()
class THEBLINDED_API ATBBaseEnemyAIController : public AAIController
{
    GENERATED_BODY()

protected:
    virtual void OnPossess(APawn* InPawn) override;
};
