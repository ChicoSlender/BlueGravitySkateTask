#include "SkateCharacter/SkateCharacterMovementComponent.h"

USkateCharacterMovementComponent::USkateCharacterMovementComponent()
{
	bUseSeparateBrakingFriction = true;
	BrakingDecelerationWalking = 500.0f;
	bOrientRotationToMovement = true;
}
