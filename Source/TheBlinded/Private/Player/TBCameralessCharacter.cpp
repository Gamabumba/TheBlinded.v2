// The Blinded Game by XTOR Team, All Rights Reserved.

#include "Player/TBCameralessCharacter.h"
#include "Camera/CameraComponent.h"
#include "Component/TBMeleeWeaponComponent.h"
#include "Component/TBWeaponComponent.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "Components/TextRenderComponent.h"
#include "Player/TBHealthComponent.h"
#include "Player/TBPlayerController.h"
#include "TBUtils.h"
#include "UI/TBHUD.h"
#include "Weapon/TBBaseWeapon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogCameralessCharacter, All, All)

ATBCameralessCharacter::ATBCameralessCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    /*MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComponent");
    MeshComponent->SetupAttachment(GetRootComponent());*/
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character
    CameraBoom->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(
        CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom
                                                      // adjust to match the controller orientation
    CameraComponent->bUsePawnControlRotation = false;

    HealthComponent = CreateDefaultSubobject<UTBHealthComponent>("HealthComponent");

    HealthTextComponent = CreateDefaultSubobject<UTextRenderComponent>("HealthTextComponent");
    HealthTextComponent->SetupAttachment(GetRootComponent());

    CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
    CollisionComponent->InitSphereRadius(500.0f);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    CollisionComponent->SetupAttachment(ACharacter::GetMesh());

    // MeleeWeaponComponent = CreateDefaultSubobject<UTBMeleeWeaponComponent>("MeleeWeaponComponent");
    // MeleeWeaponComponent->SetupAttachment(ACharacter::GetMesh());

    WeaponComponent = CreateDefaultSubobject<UTBWeaponComponent>("WeaponComponent");
}

void ATBCameralessCharacter::NotifyActorBeginOverlap(AActor *OtherActot)
{
    Super::NotifyActorBeginOverlap(OtherActot);
    const auto Pawn = Cast<APawn>(OtherActot);
    ApplyDamageTo(Pawn);
}

void ATBCameralessCharacter::BeginPlay()
{
    Super::BeginPlay();

    HealthComponent->OnDeath.AddUObject(this, &ATBCameralessCharacter::OnDeath);
}

void ATBCameralessCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //FVector MeshForVector = GetMesh()->GetForwardVector();
    const auto Health = HealthComponent->GetHealth();
    HealthTextComponent->SetText(FText::FromString(FString::Printf(TEXT("%.0f"), Health)));
        // Rotate(this);
}

void ATBCameralessCharacter::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(WeaponComponent)

        PlayerInputComponent->BindAxis("MoveForward", this, &ATBCameralessCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveBackward", this, &ATBCameralessCharacter::MoveBackward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ATBCameralessCharacter::MoveRight);
    PlayerInputComponent->BindAxis("MoveLeft", this, &ATBCameralessCharacter::MoveLeft);

    PlayerInputComponent->BindAction("Fire", IE_Pressed, WeaponComponent, &UTBWeaponComponent::Fire);
    if (PunchIsOut == false)
    {
        PlayerInputComponent->BindAction("Punch", IE_Pressed, this, &ATBCameralessCharacter::Punch);
    }
}

void ATBCameralessCharacter::MoveForward(float Amount)
{
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ATBCameralessCharacter::MoveBackward(float Amount)
{
    AddMovementInput(GetActorForwardVector(), Amount);

    APlayerController *control = Cast<APlayerController>(Controller);


        if (control->IsInputKeyDown(EKeys::S))
        {
            if (control->IsInputKeyDown(EKeys::W))
            {
                MoveForward(float(-Amount));
            }
        }

}

void ATBCameralessCharacter::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}
void ATBCameralessCharacter::MoveLeft(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);

    APlayerController *control = Cast<APlayerController>(Controller);

        if (control->IsInputKeyDown(EKeys::A))
        {
            if (control->IsInputKeyDown(EKeys::D))
            {
                MoveRight(float(-Amount));
            }
        }

}

void ATBCameralessCharacter::Punch()
{

    UE_LOG(LogTemp, Warning, TEXT("E is pressed"));
    PunchIsOut = true;
    USphereComponent *ColComponent = TBUtils::GetTBPlayerComponent<USphereComponent>(this);
    ColComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(GetOwner());
    ColComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
    FTimerHandle PunchTimerHandle;
    GetWorldTimerManager().SetTimer(PunchTimerHandle, this, &ATBCameralessCharacter::StopPunch, PunchTime);
}

bool ATBCameralessCharacter::ApplyDamageTo(APawn *OtherPawn)
{
    const auto OtherHealthComponent = TBUtils::GetTBPlayerComponent<UTBHealthComponent>(OtherPawn);
    if (!OtherHealthComponent) return false;
    return OtherHealthComponent->TryToAddDamage(DamageAmount);
}

 void ATBCameralessCharacter::StopPunch()
{
     PunchIsOut = false;
 }

 void ATBCameralessCharacter::OnDeath()
 {
     UE_LOG(LogTemp, Warning, TEXT("DEAD"));
     GetCharacterMovement()->DisableMovement();

     PlayAnimMontage(DeathAnimMontage);
     //SetLifeSpan(4.0f);
 }

// void ATBCameralessCharacter::Rotata(ATBCameralessCharacter *Player)
//{
//    const auto Control = Player->GetController<ATBPlayerController>();
//    MakeArray();
//    auto HitRes = Control->GetHitResultUnderCursorByChannel(Block)
//}

// void ATBCameralessCharacter::Rotate(ATBCameralessCharacter* Player)
//{
//    const auto Control = Player->GetController<ATBPlayerController>();
//    float x, y;
//    const auto HUD = Control->GetHUD<ATBHUD>();
//    int32 X = HUD->GetX();
//    int32 Y = HUD->GetY();
//    const TInterval<float> Center(X * 0.5f, Y * 0.5f);
//    Control->GetMousePosition(x, y);
//    const TInterval<float> Mouse(x, y);
//    FVector Fwd(x - X, y - Y, 0.0f);
//    FVector InFwd = Player->GetActorForwardVector();
//    float RotaX = Fwd.Y - InFwd.Y;
//    float RotaY = Fwd.Z - InFwd.Z;
//    float angle = acos((double)((Fwd.X * InFwd.X + Fwd.Y * InFwd.Y) /
//                                (sqrt(Fwd.X * Fwd.X + Fwd.Y * Fwd.Y) * sqrt(InFwd.X * InFwd.X + InFwd.Y * InFwd.Y))));
//    FRotator RotaFwd(0.0f, angle, 0.0f);
//    UE_LOG(LogTemp, Warning, TEXT("%f"), angle);
//    UE_LOG(LogTemp, Warning, TEXT("%d"), X);
//    UE_LOG(LogTemp, Warning, TEXT("%d"), Y);
//    UE_LOG(LogTemp, Warning, TEXT("%d"), x);
//    UE_LOG(LogTemp, Warning, TEXT("%d"), y);
//    Player->SetActorRotation(RotaFwd, ETeleportType::TeleportPhysics);
//}