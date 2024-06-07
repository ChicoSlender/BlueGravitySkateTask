#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SkatePlayerState.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FPointsChangeDelegateSignature, int);

UCLASS()
class BLUEGRAVITYSKATETASK_API ASkatePlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	ASkatePlayerState();

	FPointsChangeDelegateSignature OnPointsChangeEvent;
	
	UFUNCTION(BlueprintPure) int GetPoints() const { return points; }
	void AddPoints(int deltaPoints);
	
protected:
	int points;
};
