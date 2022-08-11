// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "TBWeaponComponent.generated.h"

class ATBBaseWeapon;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class THEBLINDED_API UTBWeaponComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UTBWeaponComponent();

    void Fire();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<ATBBaseWeapon> WeaponClass;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FName WeaponAttachPointName = "WeaponSocket";


    virtual void BeginPlay() override;

private:
    UPROPERTY()
    ATBBaseWeapon *CurrentWeapon = nullptr;

    void SpawnWeapon();
};
