// The Blinded Game by XTOR Team, All Rights Reserved.


#include "PuckUp/TBAddDamagePickUp.h"
//#include "GameFramework/CharacterMovementComponent.h"
#include "TBUtils.h"
#include "Player/TBCameralessCharacter.h"

bool ATBAddDamagePickUp::GivePickUpTo(APawn *PlayerPawn)
{
    const auto Player = Cast<ATBCameralessCharacter>(PlayerPawn);
    // const auto MovementComponent = TBUtils::GetTBPlayerComponent<UCharacterMovementComponent>(Player);
    if (!Player) return false;
    // FTimerHandle SpeedTimerHandle;
    // GetWorldTimerManager().SetTimer(SpeedTimerHandle, this, &ATBSpeedPickUp::DecreaseSpeed, BonusLifeTime);
    Player->ModifyDamageAmount(DamageModifier); // GetMovementComponent()->GetMaxSpeed();
    return true;
}
