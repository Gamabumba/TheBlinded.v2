// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TBHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeathSignature); // Signature);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class THEBLINDED_API UTBHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UTBHealthComponent();

    FOnDeathSignature OnDeath;

    float GetHealth() const
    {
        return Health;
    }

    bool TryToAddHealth(float HealthAmount);
    bool IsHealthFull() const;
    bool TryToAddDamage(float DamageAmount);

    UFUNCTION(BlueprintCallable, Category = "Health")
    bool IsDead() const
    {
        return FMath::IsNearlyZero(Health);
    }
    UFUNCTION(BlueprintCallable, Category = "Health")
    float GetHealthPercent() const
    {
        return Health / MaxHealth;
    
    }
    void SetHealth(float NewHealth);


protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (ClampMin = "0", ClampMax = "200"));
    float MaxHealth = 100.0f;

    // Called when the game starts
    virtual void BeginPlay() override;


private:
    float Health = 0.0f;

    UFUNCTION()
    void OnTakeAnyDamageHandle(AActor *DamagedActor, float Damage, const class UDamageType *DamageType,
                               class AController *InstigatedBy, AActor *DamageCauser);
};
