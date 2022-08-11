// The Blinded Game by XTOR Team, All Rights Reserved.


#include "PuckUp/TBHealthPickUp.h"
#include "Player/TBHealthComponent.h"
#include "TBUtils.h"

bool ATBHealthPickUp::GivePickUpTo(APawn *PlayerPawn)
{
    const auto HealthComponent = TBUtils::GetTBPlayerComponent<UTBHealthComponent>(PlayerPawn);
    if (!HealthComponent) return false;
    return HealthComponent->TryToAddHealth(HealthAmount);

}
