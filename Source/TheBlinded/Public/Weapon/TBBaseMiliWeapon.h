// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TBBaseMiliWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class THEBLINDED_API ATBBaseMiliWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATBBaseMiliWeapon();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent *WeaponMesh;

	virtual void BeginPlay() override;

	APlayerController *GetPlayerController() const;



};
