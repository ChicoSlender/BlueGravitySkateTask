#include "Player/SkatePlayerState.h"

ASkatePlayerState::ASkatePlayerState()
{
	points = 0;
}

void ASkatePlayerState::AddPoints(int deltaPoints)
{
	points += deltaPoints;
}
