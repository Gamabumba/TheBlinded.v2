// The Blinded Game by XTOR Team, All Rights Reserved.

#include "Weapon/TBBaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseWeapon, All, All)

ATBBaseWeapon::ATBBaseWeapon()
{
    PrimaryActorTick.bCanEverTick = false;

    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
    SetRootComponent(WeaponMesh);
}

void ATBBaseWeapon::BeginPlay()
{
    Super::BeginPlay();

    check(WeaponMesh);
}

void ATBBaseWeapon::Fire()
{
    UE_LOG(LogBaseWeapon, Display, TEXT("Fire!"));

    MakeShot();
}

void ATBBaseWeapon::MakeShot()
{
    if (!GetWorld()) return;

    FVector TraceStart, TraceEnd;
    if (!GetTraceData(TraceStart, TraceEnd)) return;

    FHitResult HitResult;
    MakeHit(HitResult, TraceStart, TraceEnd);

    if (HitResult.bBlockingHit)
    {
        MakeDamage(HitResult);
        // Drawing bullet trace line
        DrawDebugLine(GetWorld(), GetMuzzleWorldLocation(), TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
        // Drawing a sphere on the first hit point
        DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 5.0f);
    }
    else
    {
        // Drawing bullet trace line
        DrawDebugLine(GetWorld(), GetMuzzleWorldLocation(), TraceEnd, FColor::Green, false, 3.0f, 0, 3.0f);
    }
}

/// <summary>
/// Making damage to hitted actor
/// </summary>
/// <param name="HitResult">is hit information box</param>
void ATBBaseWeapon::MakeDamage(const FHitResult &HitResult)
{
    const auto DamageActor = HitResult.GetActor();
    if (!DamageActor) return;

    UE_LOG(LogBaseWeapon, Display, TEXT("Actor took the damage"));

    DamageActor->TakeDamage(DamageAmount, FDamageEvent(), GetPlayerController(), this);
}

/// <summary>
/// Getting player controller
/// </summary>
/// <returns>Player controller</returns>
APlayerController *ATBBaseWeapon::GetPlayerController() const
{
    const auto Player = Cast<ACharacter>(GetOwner()); // Getting weapon owner
    if (!Player) return nullptr;                      // Nullptr checking

    return Player->GetController<APlayerController>();
}

/// <summary>
/// Getting muzzle world location
/// </summary>
/// <returns>FVector with muzzle world location</returns>
FVector ATBBaseWeapon::GetMuzzleWorldLocation() const
{
    return WeaponMesh->GetSocketLocation(MyzzleSocketName);
}

/// <summary>
/// Getting and finding start and end trace vector
/// </summary>
/// <param name="TraceStart"> is shot trace start vector</param>
/// <param name="TraceEnd">is shot trace end vector</param>
/// <returns>bool</returns>
bool ATBBaseWeapon::GetTraceData(FVector &TraceStart, FVector &TraceEnd) const
{
    // Getting weapon owner
    const auto Player = Cast<ACharacter>(GetOwner());
    if (!Player) return false;

    // Getting weapon rotating angle
    float WeaponRotating = Player->GetTransform().GetRotation().X;
    // Getting weapon location vector
    FVector WeaponLocation = this->GetTransform().GetLocation();

    // Finding start trace vector
    TraceStart = WeaponLocation;

    // Finding end trace vector
    if (FMath::Abs(FMath::Cos(WeaponRotating)) < 0.0001)
    {
        TraceEnd.X = WeaponLocation.X;
        TraceEnd.Y = WeaponLocation.Y + TraceMaxDistance;
    }
    else if (FMath::Abs(FMath::Sin(WeaponRotating)) < 0.0001)
    {
        TraceEnd.X = WeaponLocation.X + TraceMaxDistance;
        TraceEnd.Y = WeaponLocation.Y;
    }
    else
    {
        TraceEnd.X = WeaponLocation.X + TraceMaxDistance / (FMath::Sin(WeaponRotating));
        TraceEnd.Y = WeaponLocation.Y + TraceMaxDistance / (FMath::Cos(WeaponRotating));
    }
    TraceEnd.Z = WeaponLocation.Z;

    return true;
}

/// <summary>
/// Returning the information about object that was hit first, and setting collision params
/// </summary>
/// <param name="HitResult"> is hit information box</param>
/// <param name="TraceStart"> is shot trace start vector</param>
/// <param name="TraceEnd">is shot trace end vector</param>
void ATBBaseWeapon::MakeHit(FHitResult &HitResult, const FVector &TraceStart, const FVector &TraceEnd)
{
    if (!GetWorld()) return;

    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetOwner());

    // Returning information about object that was hit first
    GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility,
                                         CollisionParams);
}