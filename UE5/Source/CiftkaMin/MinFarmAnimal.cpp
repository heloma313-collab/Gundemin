#include "MinFarmAnimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
AMinFarmAnimal::AMinFarmAnimal()
{
    PrimaryActorTick.bCanEverTick = false;
    Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
    SetRootComponent(Body);
    Head = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Head"));
    Head->SetupAttachment(Body);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMesh(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
    if (SphereMesh.Succeeded()) { Body->SetStaticMesh(SphereMesh.Object); Head->SetStaticMesh(SphereMesh.Object); }
    Body->SetRelativeScale3D(FVector(1.0f, 0.72f, 0.65f));
    Head->SetRelativeLocation(FVector(75.0f, 0.0f, 35.0f));
    Head->SetRelativeScale3D(FVector(0.42f));
    Body->SetCollisionProfileName(TEXT("BlockAll"));
    Head->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
void AMinFarmAnimal::SetAnimalType(EMinAnimalType NewType) { AnimalType = NewType; }
void AMinFarmAnimal::Interact()
{
    ++ProductCount;
    const TCHAR* Product = AnimalType == EMinAnimalType::Cow || AnimalType == EMinAnimalType::Goat ? TEXT("Şîr / Süt") :
        AnimalType == EMinAnimalType::Chicken ? TEXT("Hêk / Yumurta") :
        AnimalType == EMinAnimalType::Sheep ? TEXT("Hirî / Yün") : TEXT("XP");
    if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("%s toplandı! Toplam: %d"), Product, ProductCount));
}