// The Blinded Game by XTOR Team, All Rights Reserved.


#include "UI/TBHUD.h"
#include "Engine/Canvas.h"
#include "Blueprint/UserWidget.h"

//ATBHUD::ATBHUD()
//{
//    //PrimaryActorTick.bCanEverTick = true;
//
//    //GetCanvasSize();
//    /*DrawWidjet();*/
//}

//void ATBHUD::DrawHUD()
//{
//    Super::DrawHUD();
//
//    GetCanvasSize();
//}

//void ATBHUD::Tick(float DeltaTime)
//{
//    Super::Tick(DeltaTime);
//
//    GetCanvasSize();
//}

void ATBHUD::BeginPlay()
{
    Super::BeginPlay();

    //float NewX = 400.0f; // Canvas->SizeX;
    //float NewY = 400.0f; // Canvas->SizeY;
    //SetX(NewX);
    //SetY(NewY);
    /*if (GetWorld)
    {
        UE_LOG(LogTemp, Warning, TEXT("World is created"));
    }*/
        auto PlayerHUDWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDWidgetClass);
        if (PlayerHUDWidget)
        {
            PlayerHUDWidget->AddToViewport();
        }
    
    
}

//void ATBHUD::GetCanvasSize()
//{
//    /*if (Canvas)
//    {*/
//        int32 NewX = Canvas->SizeX;
//        int32 NewY = Canvas->SizeY;
//        SetX(NewX);
//        SetY(NewY);
//    //}
//}



