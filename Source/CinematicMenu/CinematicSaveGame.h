#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CinematicSaveGame.generated.h"

/**
 * Stores persistent data like Graphics Settings and Audio Volume
 */
UCLASS()
class CINEMATICMENU_API UCinematicSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UCinematicSaveGame();

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;

	// SETTINGS DATA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float MasterVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	float MouseSensitivity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool bInvertYAxis;
};
