// The Blinded Game by XTOR Team, All Rights Reserved.


#include "Component/TBMeleeWeaponComponent.h"
#include "TBUtils.h"
#include "Player/TBCameralessCharacter.h"
#include "Components/SphereComponent.h"
#include "Player/TBHealthComponent.h"


// Sets default values for this component's properties
UTBMeleeWeaponComponent::UTBMeleeWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

    /*CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(500.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    FAttachmentTransformRules AttachmentRules(EAttachmentRule::KeepRelative, false);
    ACharacter *Character = Cast<ACharacter>(GetOwner());
    if (!Character) return;
    CollisionComponent->AttachToComponent(Character->GetMesh(), AttachmentRules);*/
    
	// ...
}


// Called when the game starts
void UTBMeleeWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTBMeleeWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//void UTBMeleeWeaponComponent::Punch()
//{
//
//    //UE_LOG(LogTemp, Warning, TEXT("E is pressed"));
//
//    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
//    FCollisionQueryParams CollisionParams;
//    CollisionParams.AddIgnoredActor(GetOwner());
//    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
//    /*FTimerHandle PunchTimerHandle;
//    GetWorldTimerManager().SetTimer(PunchTimerHandle, this, &ATBCameralessCharacter::StopPunch, PunchTime);*/
//}

//bool UTBMeleeWeaponComponent::ApplyDamageTo(APawn *OtherPawn)
//{
//    const auto OtherHealthComponent = TBUtils::GetTBPlayerComponent<UTBHealthComponent>(OtherPawn);
//    if (!OtherHealthComponent) return false;
//    return OtherHealthComponent->TryToAddDamage(DamageAmount);
//}
//
//void UTBMeleeWeaponComponent::OnComponentBeginOverlap(AActor *OtherActot)
//{
//    //Super::OnComponentBeginOverlap(OtherActot);
//    const auto Pawn = Cast<APawn>(OtherActot);
//    ApplyDamageTo(Pawn);
//}

