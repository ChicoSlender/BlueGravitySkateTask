#include "ObstacleJump/UI/ScoreHUDWidget.h"

UScoreHUDWidget::UScoreHUDWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	Score = 0;
}

void UScoreHUDWidget::SetScore(int NewScore)
{
	Score = NewScore;
}
