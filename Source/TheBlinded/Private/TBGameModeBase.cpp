// The Blinded Game by XTOR Team, All Rights Reserved.


#include "TBGameModeBase.h"
#include "Player/TBCameralessCharacter.h"

ATBGameModeBase::ATBGameModeBase()
{
    DefaultPawnClass = ATBCameralessCharacter::StaticClass();
}
