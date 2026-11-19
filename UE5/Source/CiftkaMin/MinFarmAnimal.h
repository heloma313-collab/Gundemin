#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MinFarmAnimal.generated.h"
class UStaticMeshComponent;
UENUM(BlueprintType)
enum class EMinAnimalType : uint8 { Cow, Sheep, Chicken, Goat, Horse };
UCLASS()
class CIFTKAMIN_API AMinFarmAnimal : public AActor
{
    GENERATED_BODY()
public:
    AMinFarmAnimal();
    void Interact();
    void SetAnimalType(EMinAnimalType NewType);
protected:
    UPROPERTY(VisibleAnywhere) TObjectPtr<UStaticMeshComponent> Body;
    UPROPERTY(VisibleAnywhere) TObjectPtr<UStaticMeshComponent> Head;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animal") EMinAnimalType AnimalType = EMinAnimalType::Cow;
    int32 ProductCount = 0;
};