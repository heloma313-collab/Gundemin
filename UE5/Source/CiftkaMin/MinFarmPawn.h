#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MinFarmPawn.generated.h"
class USpringArmComponent;
class UCameraComponent;
UCLASS()
class CIFTKAMIN_API AMinFarmPawn : public APawn
{
    GENERATED_BODY()
public:
    AMinFarmPawn();
protected:
    UPROPERTY(VisibleAnywhere) TObjectPtr<USceneComponent> SceneRoot;
    UPROPERTY(VisibleAnywhere) TObjectPtr<USpringArmComponent> CameraBoom;
    UPROPERTY(VisibleAnywhere) TObjectPtr<UCameraComponent> FarmCamera;
};