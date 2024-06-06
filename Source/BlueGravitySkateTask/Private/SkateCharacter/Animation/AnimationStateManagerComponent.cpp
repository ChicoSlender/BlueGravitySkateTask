#include "SkateCharacter/Animation/AnimationStateManagerComponent.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UAnimationStateManagerComponent::UAnimationStateManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAnimationStateManagerComponent::OnJump()
{
	if (CurrentState != ONGROUND)
	{
		return;
	}

	CurrentState = JUMPING;
}


void UAnimationStateManagerComponent::OnJumpStop()
{
	if (CurrentState != JUMPING)
	{
		return;
	}

	CurrentState = FALLING;
}

void UAnimationStateManagerComponent::OnLanding()
{
	if (CurrentState != FALLING && CurrentState != JUMPING)
	{
		return;
	}

	CurrentState = ONGROUND;
}

void UAnimationStateManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (CurrentState != JUMPING || CharacterOwner == nullptr)
	{
		return;
	}

	UCharacterMovementComponent* CharacterMovement = CharacterOwner->GetCharacterMovement();

	if (CharacterMovement == nullptr)
	{
		return;
	}
	
	if (CharacterMovement->IsFalling())
	{
		if (!CharacterOwner->IsJumpProvidingForce())
		{
			OnJumpStop();
		}
	}
	else
	{
		OnLanding();
	}
}


void UAnimationStateManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	CharacterOwner = Cast<ACharacter>(GetOwner());
}
