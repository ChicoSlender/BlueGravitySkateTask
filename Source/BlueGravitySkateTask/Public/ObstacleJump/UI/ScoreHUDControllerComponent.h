#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScoreHUDControllerComponent.generated.h"


class ASkatePlayerState;
class UScoreHUDWidget;

UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLUEGRAVITYSKATETASK_API UScoreHUDControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UScoreHUDControllerComponent();

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UScoreHUDWidget> ScoreHUDClass;

	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UScoreHUDWidget* ScoreHUD;
	ASkatePlayerState* OwnerPlayerState;
	
	void HandlePlayerStatePointsChange(int NewPoints);
};
