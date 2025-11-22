#include "CinematicSaveGame.h"

UCinematicSaveGame::UCinematicSaveGame()
{
	SaveSlotName = TEXT("CinematicMenuSave");
	UserIndex = 0;

	// Default Values
	MasterVolume = 1.0f;
	MouseSensitivity = 1.0f;
	bInvertYAxis = false;
}
