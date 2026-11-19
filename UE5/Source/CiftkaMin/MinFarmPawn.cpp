#include "MinFarmPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
AMinFarmPawn::AMinFarmPawn()
{
    PrimaryActorTick.bCanEverTick = false;
    SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    SetRootComponent(SceneRoot);
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("IsometricCameraBoom"));
    CameraBoom->SetupAttachment(SceneRoot);
    CameraBoom->TargetArmLength = 1900.0f;
    CameraBoom->SetRelativeRotation(FRotator(-55.0f, 0.0f, -45.0f));
    CameraBoom->bDoCollisionTest = false;
    FarmCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FarmCamera"));
    FarmCamera->SetupAttachment(CameraBoom);
    FarmCamera->ProjectionMode = ECameraProjectionMode::Orthographic;
    FarmCamera->OrthoWidth = 2600.0f;
    AutoPossessPlayer = EAutoReceiveInput::Player0;
}