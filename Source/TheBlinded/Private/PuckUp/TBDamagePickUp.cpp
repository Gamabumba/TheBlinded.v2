// The Blinded Game by XTOR Team, All Rights Reserved.


#include "PuckUp/TBDamagePickUp.h"
#include "Player/TBHealthComponent.h"
#include "TBUtils.h"

bool ATBDamagePickUp::GivePickUpTo(APawn *PlayerPawn)
{
    const auto HealthComponent = TBUtils::GetTBPlayerComponent<UTBHealthComponent>(PlayerPawn);
    if (!HealthComponent) return false;
    return HealthComponent->TryToAddDamage(DamageAmount);
}