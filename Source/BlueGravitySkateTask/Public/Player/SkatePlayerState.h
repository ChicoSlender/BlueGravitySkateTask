#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SkatePlayerState.generated.h"

UCLASS()
class BLUEGRAVITYSKATETASK_API ASkatePlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ASkatePlayerState();

	UFUNCTION(BlueprintPure) int GetPoints() const { return points; }
	void AddPoints(int deltaPoints);
	
protected:
	int points;
};
