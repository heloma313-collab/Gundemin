#include "MinFarmPlot.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
AMinFarmPlot::AMinFarmPlot()
{
    PrimaryActorTick.bCanEverTick = false;
    Soil = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Soil"));
    SetRootComponent(Soil);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeMesh.Succeeded()) Soil->SetStaticMesh(CubeMesh.Object);
    Soil->SetRelativeScale3D(FVector(1.6f, 1.6f, 0.12f));
    Soil->SetCollisionProfileName(TEXT("BlockAll"));
}
void AMinFarmPlot::Interact()
{
    bReadyToHarvest = !bReadyToHarvest;
    if (bReadyToHarvest) {
        if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Tohum ekildi. Tekrar dokununca hasat edilecek."));
    } else {
        ++HarvestCount;
        if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Hasat! Buğday toplamı: %d"), HarvestCount));
    }
}