#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MinFarmGameMode.generated.h"
UCLASS()
class CIFTKAMIN_API AMinFarmGameMode : public AGameModeBase
{
    GENERATED_BODY()
public:
    AMinFarmGameMode();
    virtual void BeginPlay() override;
};