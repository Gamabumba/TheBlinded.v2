// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PuckUp/TBBasePickUp.h"
#include "TBAddDamagePickUp.generated.h"

/**
 * 
 */
UCLASS()
class THEBLINDED_API ATBAddDamagePickUp : public ATBBasePickUp
{
	GENERATED_BODY()
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PickUp", meta = (ClampMin = "1.0", ClampMax = "100.0"))
    float DamageModifier = 2.0f;

private:
    virtual bool GivePickUpTo(APawn *PlayerPawn) override;
};
