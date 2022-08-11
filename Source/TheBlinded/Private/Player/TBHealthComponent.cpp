// The Blinded Game by XTOR Team, All Rights Reserved.

#include "Player/TBHealthComponent.h"
#include "GameFramework/Actor.h"

UTBHealthComponent::UTBHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UTBHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    SetHealth(MaxHealth);

    check(MaxHealth > 0);

    AActor *ComponentOwner = GetOwner(); // Получение указателя на владельца данного компонента
    if (ComponentOwner)
    {
        ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UTBHealthComponent::OnTakeAnyDamageHandle); // Подписка на делегат
    }
}

void UTBHealthComponent::SetHealth(float NewHealth)
{
    Health = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
}

bool UTBHealthComponent::TryToAddHealth(float HealthAmount)
{
    if (IsHealthFull() || IsDead()) return false;
    SetHealth(Health + HealthAmount/2);
    return true;
}

bool UTBHealthComponent::TryToAddDamage(float DamageAmount)
{
    if (DamageAmount <= 0.0 || IsDead() || !GetWorld()) return false;
    SetHealth(Health - DamageAmount);
    UE_LOG(LogTemp, Warning, TEXT("DAMAGE"));
    // Check to the actor dead
    if (IsDead())
    {
        // Needed functions broadcast
        OnDeath.Broadcast();
    }
    return true;
}

bool UTBHealthComponent::IsHealthFull() const
{
    return FMath::IsNearlyEqual(Health, MaxHealth); 
}

void UTBHealthComponent::OnTakeAnyDamageHandle(AActor *DamagedActor, float Damage, const UDamageType *DamageType,
                                                      AController *InstigatedBy, AActor *DamageCauser)
{
    if (Damage <= 0.0 || IsDead() || !GetWorld()) return;

    SetHealth(Health - Damage);
    UE_LOG(LogTemp, Warning, TEXT("DAMAGE"));
    // Check to the actor dead
    if (IsDead())
    {
        // Needed functions broadcast
        OnDeath.Broadcast();
    }
}
