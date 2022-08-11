// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TBMeleeWeaponComponent.generated.h"

class USphereComponent;
class AActor;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEBLINDED_API UTBMeleeWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTBMeleeWeaponComponent();

	//void Punch();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Melee Punch", meta = (ClampMin = "1.0", ClampMax = "100.0"))
    float DamageAmount = 10.0f;*/

	/*UPROPERTY(VisibleAnywhere, Category = "Components")
    USphereComponent *CollisionComponent;*/

	/*UFUNCTION(BlueprintCallable)
	virtual void OnComponentBeginOverlap(AActor *OtherActot);*/

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

private:
    //void Punch();
	/*bool ApplyDamageTo(APawn *OtherPawn);*/
		
};
