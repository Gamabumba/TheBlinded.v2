// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TBHUD.generated.h"

/**
 * 
 */
UCLASS()
class THEBLINDED_API ATBHUD : public AHUD
{
	GENERATED_BODY()
public:
    //ATBHUD();
    //virtual void DrawHUD() override;
    int32 X = 0;
    int32 Y = 0;
    int32 GetX()
    {
        return X;
    }
    int32 GetY()
    {
        return Y;
    }
    void SetX(int32 NewX)
    {
        X = NewX;
    }
    void SetY(int32 NewY)
    {
        Y = NewY;
    }
    //virtual void Tick(float DeltaTime) override;
		protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

	virtual void BeginPlay() override;

    private:


    //void GetCanvasSize();

    void DrawWidjet();
    
};
