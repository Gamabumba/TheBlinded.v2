// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PuckUp/TBBasePickUp.h"
#include "TBSpeedPickUp.generated.h"

/**
 * 
 */
UCLASS()
class THEBLINDED_API ATBSpeedPickUp : public ATBBasePickUp
{
	GENERATED_BODY()
protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PickUp")
    float SpeedAmount = 2.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PickUp")
    float BonusLifeTime = 3.0f;

private:
    virtual bool GivePickUpTo(APawn *PlayerPawn) override;
    //void DecreaseSpeed();
};
