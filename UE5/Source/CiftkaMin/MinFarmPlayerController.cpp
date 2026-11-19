#include "MinFarmPlayerController.h"
#include "MinFarmAnimal.h"
#include "MinFarmPlot.h"
#include "Engine/World.h"
AMinFarmPlayerController::AMinFarmPlayerController()
{
    bShowMouseCursor = true;
    bEnableTouchEvents = true;
    bEnableClickEvents = true;
}
void AMinFarmPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindTouch(IE_Pressed, this, &AMinFarmPlayerController::HandleTap);
    InputComponent->BindAction("FarmSelect", IE_Pressed, this, &AMinFarmPlayerController::HandleClick);
}
void AMinFarmPlayerController::HandleTap(ETouchIndex::Type, FVector Location) { InteractAt(FVector2D(Location.X, Location.Y)); }
void AMinFarmPlayerController::HandleClick()
{
    float X=0, Y=0;
    if (GetMousePosition(X,Y)) InteractAt(FVector2D(X,Y));
}
void AMinFarmPlayerController::InteractAt(const FVector2D& ScreenPosition)
{
    FHitResult Hit;
    if (GetHitResultAtScreenPosition(ScreenPosition, ECC_Visibility, false, Hit) && Hit.GetActor())
    {
        if (AMinFarmAnimal* Animal = Cast<AMinFarmAnimal>(Hit.GetActor())) Animal->Interact();
        else if (AMinFarmPlot* Plot = Cast<AMinFarmPlot>(Hit.GetActor())) Plot->Interact();
    }
}