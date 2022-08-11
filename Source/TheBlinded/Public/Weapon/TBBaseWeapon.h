// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TBBaseWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class THEBLINDED_API ATBBaseWeapon : public AActor
{
    GENERATED_BODY()

public:
    ATBBaseWeapon();
    virtual void Fire();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent *WeaponMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    FName MyzzleSocketName = "MuzzleSocket";

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float TraceMaxDistance = 1500.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    float DamageAmount = 15.0f;

    virtual void BeginPlay() override;

    void MakeShot();

    APlayerController *GetPlayerController() const;
    FVector GetMuzzleWorldLocation() const;
    bool GetTraceData(FVector &TraceStart, FVector &TraceEnd) const;
    void MakeHit(FHitResult &HitResult, const FVector &TraceStart, const FVector &TraceEnd);

    void MakeDamage(const FHitResult &HitResult);
};
