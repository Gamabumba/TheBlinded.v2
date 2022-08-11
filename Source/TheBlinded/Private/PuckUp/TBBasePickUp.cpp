// The Blinded Game by XTOR Team, All Rights Reserved.


#include "PuckUp/TBBasePickUp.h"
#include "Components/SphereComponent.h"

// Sets default values
ATBBasePickUp::ATBBasePickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(50.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    SetRootComponent(CollisionComponent);

}

// Called when the game starts or when spawned
void ATBBasePickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATBBasePickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    check(CollisionComponent);
}


void ATBBasePickUp::NotifyActorBeginOverlap(AActor *OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);
    const auto Pawn = Cast<APawn>(OtherActor);
    if (GivePickUpTo(Pawn))
    {
        PickUpWasTaken();
        
    }
    
}

bool ATBBasePickUp::GivePickUpTo(APawn *PlayerPawn)
{
    return false;
}


void ATBBasePickUp::PickUpWasTaken()
{
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    if (GetRootComponent())
    {
        //UE_LOG(LogTemp, Warning, TEXT("Root is here"));
        GetRootComponent()->SetVisibility(false, true);
    }
    FTimerHandle RespawnTimerHandle;
    GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &ATBBasePickUp::Respawn, RespawnTime);


}

void ATBBasePickUp::Respawn()
{
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    if (GetRootComponent())
    {

        GetRootComponent()->SetVisibility(true, true);
    }
}
