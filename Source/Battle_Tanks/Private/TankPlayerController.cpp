#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Possesing A Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possesing: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // OUT Parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "Side-Effect", Is Going To Line Trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString())
		// TODO Tell Controlled Tank To Aim At This Point
	}
}

// Get World Location Of LineTrace Though Crosshair, True If Hits Landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find The Crosshair Position In Pixel Coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// "De-Project" The Screen Position Of The Crosshair To A World Direction
	FVector CameraWorldLocation;
	FVector WorldDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, WorldDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *WorldDirection.ToString());
	}

	// Line Trace Along That Look Direction, And See What We Hit (Up To Max Range) 
	return true;
}