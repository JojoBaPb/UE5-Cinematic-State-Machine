#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CinematicCameraActor.generated.h"

// Define our Menu States
UENUM(BlueprintType)
enum class EMenuState : uint8
{
	MainMenu    UMETA(DisplayName = "Main Menu"),
	Settings    UMETA(DisplayName = "Settings"),
	Play        UMETA(DisplayName = "Play Mode"),
	None        UMETA(DisplayName = "None")
};

// A struct to hold data for each camera position
USTRUCT(BlueprintType)
struct FMenuCameraTarget
{
	GENERATED_BODY()

	// The artist drops an empty actor here in the world to set the view
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	AActor* CameraAnchor;

	// How fast to move to this position
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	float InterpolationSpeed = 3.0f;
};

UCLASS()
class CINEMATICMENU_API ACinematicCameraActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACinematicCameraActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// Call this from your UI Widgets (Buttons)
	UFUNCTION(BlueprintCallable, Category = "Cinematic System")
	void SetMenuState(EMenuState NewState);

private:
	// The current state of the menu
	EMenuState CurrentState;

	// The target transform we are trying to reach
	FVector TargetLocation;
	FRotator TargetRotation;
	float CurrentInterpSpeed;

	// CONFIGURATION: Map states to targets
	// This allows the designer to add keys in the editor
	UPROPERTY(EditAnywhere, Category = "Cinematic Configuration")
	TMap<EMenuState, FMenuCameraTarget> CameraTargets;
};
