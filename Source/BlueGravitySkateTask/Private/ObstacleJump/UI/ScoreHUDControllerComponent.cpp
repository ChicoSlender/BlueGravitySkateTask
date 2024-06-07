#include "ObstacleJump/UI/ScoreHUDControllerComponent.h"
#include "Blueprint/UserWidget.h"
#include "ObstacleJump/UI/ScoreHUDWidget.h"
#include "Player/SkatePlayerState.h"

UScoreHUDControllerComponent::UScoreHUDControllerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UScoreHUDControllerComponent::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* OwnerController = Cast<APlayerController>(GetOwner());

	if (OwnerController == nullptr)
	{
		return;
	}

	OwnerPlayerState = OwnerController->GetPlayerState<ASkatePlayerState>();

	if (OwnerPlayerState == nullptr)
	{
		return;
	}

	ScoreHUD = CreateWidget<UScoreHUDWidget>(OwnerController, ScoreHUDClass);

	OwnerPlayerState->OnPointsChangeEvent.AddUObject(this, &UScoreHUDControllerComponent::HandlePlayerStatePointsChange);

	const int CurrentScore = OwnerPlayerState->GetPoints();
	ScoreHUD->SetScore(CurrentScore);
	ScoreHUD->AddToViewport();
}


void UScoreHUDControllerComponent::HandlePlayerStatePointsChange(int NewPoints)
{
	ScoreHUD->SetScore(NewPoints);
}
