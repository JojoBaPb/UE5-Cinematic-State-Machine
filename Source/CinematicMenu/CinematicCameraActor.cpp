#include "CinematicCameraActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACinematicCameraActor::ACinematicCameraActor()
{
	PrimaryActorTick.bCanEverTick = true;
	CurrentState = EMenuState::None;
	CurrentInterpSpeed = 2.0f;
}

// Called when the game starts or when spawned
void ACinematicCameraActor::BeginPlay()
{
	Super::BeginPlay();

	// Initialize target to current location so we don't snap weirdly at start
	TargetLocation = GetActorLocation();
	TargetRotation = GetActorRotation();

	// Optional: Possess this actor immediately as the view target
	APlayerController *PC = UGameplayStatics::GetPlayerController(this, 0);
	if (PC)
	{
		PC->SetViewTargetWithBlend(this, 0.0f);
	}

	// Start at Main Menu by default
	SetMenuState(EMenuState::MainMenu);
}

// Called every frame
void ACinematicCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 1. Get Current Transform
	FVector CurrentLoc = GetActorLocation();
	FRotator CurrentRot = GetActorRotation();

	// 2. Smoothly Interpolate to Target
	// VInterpTo creates that smooth "ease-out" movement
	FVector NewLoc = FMath::VInterpTo(CurrentLoc, TargetLocation, DeltaTime, CurrentInterpSpeed);
	FRotator NewRot = FMath::RInterpTo(CurrentRot, TargetRotation, DeltaTime, CurrentInterpSpeed);

	// 3. Apply Transform
	SetActorLocation(NewLoc);
	SetActorRotation(NewRot);
}

void ACinematicCameraActor::SetMenuState(EMenuState NewState)
{
	// Check if the state exists in our configuration map
	if (CameraTargets.Contains(NewState))
	{
		CurrentState = NewState;

		// Retrieve the config struct
		FMenuCameraTarget TargetData = CameraTargets[NewState];

		// If the designer set an anchor, use its location
		if (TargetData.CameraAnchor)
		{
			TargetLocation = TargetData.CameraAnchor->GetActorLocation();
			TargetRotation = TargetData.CameraAnchor->GetActorRotation();
			CurrentInterpSpeed = TargetData.InterpolationSpeed;
		}
	}
}
