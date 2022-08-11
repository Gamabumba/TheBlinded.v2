// The Blinded Game by XTOR Team, All Rights Reserved.

#include "Component/TBWeaponComponent.h"
#include "GameFramework/Character.h"
#include "Weapon/TBBaseWeapon.h"

DEFINE_LOG_CATEGORY_STATIC(LogWeaponComponent, All, All)

UTBWeaponComponent::UTBWeaponComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UTBWeaponComponent::BeginPlay()
{
    Super::BeginPlay();

    SpawnWeapon();
}

void UTBWeaponComponent::SpawnWeapon()
{
    if (!GetWorld()) return;

    // Getting pointer to pawn
    ACharacter *Character = Cast<ACharacter>(GetOwner());
    if (!Character) return;

    // Spawning gun
    CurrentWeapon = GetWorld()->SpawnActor<ATBBaseWeapon>(WeaponClass);
    if (!CurrentWeapon) return;

    // Creating attachment rules for attaching this Actor to mesh
    FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
    // Attaching this Actor to mesh
    CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRules, WeaponAttachPointName);
    // Setting owner
    CurrentWeapon->SetOwner(Character);

    UE_LOG(LogWeaponComponent, Display, TEXT("Weapon was spawned and attached!"));
}

void UTBWeaponComponent::Fire()
{
    if (!CurrentWeapon) return;
    CurrentWeapon->Fire();
}