// The Blinded Game by XTOR Team, All Rights Reserved.

#include "Enemy/TBBaseEnemyCharacter.h"
#include "Components/TextRenderComponent.h"
#include "Player/TBHealthComponent.h"

// Sets default values
ATBBaseEnemyCharacter::ATBBaseEnemyCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need
    // it.
    PrimaryActorTick.bCanEverTick = true;

    HealthComponent = CreateDefaultSubobject<UTBHealthComponent>("HealthComponent");

    HealthTextComponent = CreateDefaultSubobject<UTextRenderComponent>("HealthTextComponent");
    HealthTextComponent->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void ATBBaseEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();

    check(HealthComponent);
    HealthComponent->OnDeath.AddUObject(this, &ATBBaseEnemyCharacter::Ondeath);
}

// Called every frame
void ATBBaseEnemyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    const auto Health = HealthComponent->GetHealth();
    HealthTextComponent->SetText(FText::FromString(FString::Printf(TEXT("%.0f"), Health)));
}

// Called to bind functionality to input
void ATBBaseEnemyCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}
void ATBBaseEnemyCharacter::Ondeath()
{
    PlayAnimMontage(DeathAnimMontage);
    SetLifeSpan(4.0f);
}
