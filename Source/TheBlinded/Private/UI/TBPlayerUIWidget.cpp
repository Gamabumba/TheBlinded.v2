// The Blinded Game by XTOR Team, All Rights Reserved.


#include "UI/TBPlayerUIWidget.h"
#include "Player/TBHealthComponent.h"


float UTBPlayerUIWidget::GetHealthPercent() const 
{
    const auto Player = GetOwningPlayerPawn();
    if (!Player) return 0.0f;
    const auto Component = Player->GetComponentByClass(UTBHealthComponent::StaticClass());
    const auto HealthComponent = Cast<UTBHealthComponent>(Component);
    if (!HealthComponent) return 0.0f;
    return HealthComponent->GetHealthPercent();

}