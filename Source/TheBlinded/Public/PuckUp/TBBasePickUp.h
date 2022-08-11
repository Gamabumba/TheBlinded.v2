// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TBBasePickUp.generated.h"

class USphereComponent;

UCLASS()
class THEBLINDED_API ATBBasePickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATBBasePickUp();

protected:

	UPROPERTY(VisibleAnywhere, Category = "PickUp")
    USphereComponent *CollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PickUp")
    float RespawnTime = 1.0f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    virtual void NotifyActorBeginOverlap(AActor *OtherActot) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	private:
    virtual bool GivePickUpTo(APawn *PlayerPawn);
    void PickUpWasTaken();
        void Respawn();

};
