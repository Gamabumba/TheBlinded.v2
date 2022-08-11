// The Blinded Game by XTOR Team, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TBPlayerUIWidget.generated.h"

/**
 * 
 */
UCLASS()
class THEBLINDED_API UTBPlayerUIWidget : public UUserWidget
{
    GENERATED_BODY()

        public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    float GetHealthPercent() const;
};
