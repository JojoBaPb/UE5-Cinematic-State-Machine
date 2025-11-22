#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CinematicPlayerController.generated.h"

/**
 * Custom Controller to enable mouse interface for the Main Menu
 */
UCLASS()
class CINEMATICMENU_API ACinematicPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACinematicPlayerController();

protected:
	virtual void BeginPlay() override;
};
