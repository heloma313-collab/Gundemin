#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MinFarmPlayerController.generated.h"
UCLASS()
class CIFTKAMIN_API AMinFarmPlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    AMinFarmPlayerController();
protected:
    virtual void SetupInputComponent() override;
    void HandleTap(ETouchIndex::Type FingerIndex, FVector Location);
    void HandleClick();
    void InteractAt(const FVector2D& ScreenPosition);
};