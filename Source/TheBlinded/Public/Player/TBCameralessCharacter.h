// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TBCameralessCharacter.generated.h"

class UCameraComponent;
class UTBHealthComponent;
class UTextRenderComponent;
class UTBWeaponComponent;
class USphereComponent;
class UTBMeleeWeaponComponent;

UCLASS()
class THEBLINDED_API ATBCameralessCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ATBCameralessCharacter();

protected:
    /*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
    USkeletalMeshComponent *MeshComponent;*/

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent *CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTBHealthComponent *HealthComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTextRenderComponent *HealthTextComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTBWeaponComponent *WeaponComponent;

    /*UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTBMeleeWeaponComponent *MeleeWeaponComponent;*/
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent *CameraBoom;

    UPROPERTY(VisibleAnywhere, Category = "Components")
    USphereComponent *CollisionComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Melee Punch", meta = (ClampMin = "1.0", ClampMax = "100.0"))
    float DamageAmount = 10.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Melee Punch")
    float PunchTime = 20.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Melee Punch")
    bool PunchIsOut = false;

    UPROPERTY(EditDefaultsOnly, Category = "Animation")
    UAnimMontage *DeathAnimMontage;

    virtual void NotifyActorBeginOverlap(AActor *OtherActot) override;
    

    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;


    void ModifyDamageAmount(float NewDamage)
    {
        DamageAmount *= NewDamage;
    }

private:
    void MoveForward(float Amount);
    void MoveBackward(float Amount);
    void MoveRight(float Amount);
    void MoveLeft(float Amount);

    void Punch();
    bool ApplyDamageTo(APawn *OtherPawn);
    void StopPunch();
    void OnDeath();
    //void Rotate(ATBCameralessCharacter *Player);
    //void Rotata(ATBCameralessCharacter *Player);
};