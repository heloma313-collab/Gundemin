#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MinFarmPlot.generated.h"
class UStaticMeshComponent;
UCLASS()
class CIFTKAMIN_API AMinFarmPlot : public AActor
{
    GENERATED_BODY()
public:
    AMinFarmPlot();
    void Interact();
protected:
    UPROPERTY(VisibleAnywhere) TObjectPtr<UStaticMeshComponent> Soil;
    bool bReadyToHarvest = false;
    int32 HarvestCount = 0;
};