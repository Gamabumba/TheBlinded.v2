// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "BehaviorTree/BTTaskNode.h"
#include "CoreMinimal.h"
#include "TBNextLocationTask.generated.h"

/**
 *
 */
UCLASS()
class THEBLINDED_API UTBNextLocationTask : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UTBNextLocationTask();

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory) override;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float Radius = 1000.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FBlackboardKeySelector AimLocationKey;
};
