// The Blinded Game by XTOR Team, All Rights Reserved.


#include "Weapon/TBBaseMiliWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"

ATBBaseMiliWeapon::ATBBaseMiliWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
    SetRootComponent(WeaponMesh);

}

// Called when the game starts or when spawned
void ATBBaseMiliWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	check(WeaponMesh)
}

APlayerController *ATBBaseMiliWeapon::GetPlayerController() const
{
    const auto Player = Cast<ACharacter>(GetOwner()); // Getting weapon owner
    if (!Player) return nullptr;                      // Nullptr checking

    return Player->GetController<APlayerController>();
}



