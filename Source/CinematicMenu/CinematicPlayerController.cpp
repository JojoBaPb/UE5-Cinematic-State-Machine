#include "CinematicPlayerController.h"

ACinematicPlayerController::ACinematicPlayerController()
{
	// ENABLING MOUSE INTERFACE
	// This is critical for any Menu System
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
}

void ACinematicPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// specific UI input mode settings can go here later
	// e.g. FInputModeUIOnly InputMode;
	// SetInputMode(InputMode);
}
