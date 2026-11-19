#include "MinFarmGameMode.h"
#include "MinFarmPawn.h"
#include "MinFarmAnimal.h"
#include "MinFarmPlot.h"
#include "MinFarmPlayerController.h"
#include "Engine/World.h"
#include "Engine/StaticMeshActor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
AMinFarmGameMode::AMinFarmGameMode()
{
    DefaultPawnClass = AMinFarmPawn::StaticClass();
    PlayerControllerClass = AMinFarmPlayerController::StaticClass();
}
void AMinFarmGameMode::BeginPlay()
{
    Super::BeginPlay();
    UWorld* World = GetWorld();
    if (!World) return;
    UStaticMesh* CubeMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeMesh)
    {
        AStaticMeshActor* Ground = World->SpawnActor<AStaticMeshActor>(FVector(0,0,-70), FRotator::ZeroRotator);
        if (Ground) { Ground->GetStaticMeshComponent()->SetStaticMesh(CubeMesh); Ground->SetActorScale3D(FVector(24,18,0.5f)); Ground->SetActorEnableCollision(true); }
    }
    const FVector AnimalSpots[] = { FVector(-450,-180,40), FVector(-120,-180,40), FVector(220,-180,40), FVector(520,-180,40) };
    for (int32 i=0; i<4; ++i)
    {
        AMinFarmAnimal* Animal = World->SpawnActor<AMinFarmAnimal>(AnimalSpots[i], FRotator(0,0,0));
        if (Animal) Animal->SetAnimalType(static_cast<EMinAnimalType>(i));
    }
    for (int32 i=0; i<6; ++i)
    {
        const FVector PlotLocation(-650.0f + (i%3)*260.0f, 300.0f + (i/3)*240.0f, 12.0f);
        World->SpawnActor<AMinFarmPlot>(PlotLocation, FRotator::ZeroRotator);
    }
}