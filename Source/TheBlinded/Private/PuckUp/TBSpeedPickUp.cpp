// The Blinded Game by XTOR Team, All Rights Reserved.


#include "PuckUp/TBSpeedPickUp.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TBUtils.h"
#include "Player/TBCameralessCharacter.h"

bool ATBSpeedPickUp::GivePickUpTo(APawn *PlayerPawn)
{
    const auto Player = Cast<ATBCameralessCharacter>(PlayerPawn);
    //const auto MovementComponent = TBUtils::GetTBPlayerComponent<UCharacterMovementComponent>(Player);
    if (!Player) return false;
    //FTimerHandle SpeedTimerHandle;
    //GetWorldTimerManager().SetTimer(SpeedTimerHandle, this, &ATBSpeedPickUp::DecreaseSpeed, BonusLifeTime);
    Player->GetCharacterMovement()->MaxWalkSpeed *= SpeedAmount; // GetMovementComponent()->GetMaxSpeed();
    return true;
}

//void ATBSpeedPickUp::DecreaseSpeed()
//{
//    const auto Player = Cast<ATBCameralessCharacter>(PlayerPawn);
//    // const auto MovementComponent = TBUtils::GetTBPlayerComponent<UCharacterMovementComponent>(Player);
//    if (Player)
//    Player->GetCharacterMovement()->MaxWalkSpeed -= SpeedAmount;
//}