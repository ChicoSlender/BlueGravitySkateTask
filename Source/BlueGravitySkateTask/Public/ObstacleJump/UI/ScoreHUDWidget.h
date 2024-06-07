#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreHUDWidget.generated.h"

UCLASS()
class BLUEGRAVITYSKATETASK_API UScoreHUDWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UScoreHUDWidget(const FObjectInitializer& ObjectInitializer);

	void SetScore(int NewScore);

protected:
	UPROPERTY(BlueprintReadOnly)
	int Score;
};
