#include "SkateCharacter/SkateboardThrusterComponent.h"

#include "GameFramework/PawnMovementComponent.h"


USkateboardThrusterComponent::USkateboardThrusterComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	PawnOwner = nullptr;
	OwnerMovement = nullptr;
	bStopMovement = false;
	MaxTurnRate = 2.0f;
	TurnInput = 0.0f;
}


void USkateboardThrusterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PawnOwner == nullptr || OwnerMovement == nullptr || bStopMovement)
	{
		return;
	}

	FVector MovementDirection = PawnOwner->GetActorForwardVector();

	MovementDirection = MovementDirection.RotateAngleAxis(MaxTurnRate * TurnInput, PawnOwner->GetActorUpVector());
	
	OwnerMovement->AddInputVector(MovementDirection);

	TurnInput = 0.0f;
}

void USkateboardThrusterComponent::Stop()
{
	bStopMovement = true;
}

void USkateboardThrusterComponent::Start()
{
	bStopMovement = false;
}

void USkateboardThrusterComponent::Turn(float Scale)
{
	TurnInput = Scale;
}


void USkateboardThrusterComponent::BeginPlay()
{
	Super::BeginPlay();

	PawnOwner = Cast<APawn>(GetOwner());

	if (PawnOwner == nullptr)
	{
		return;
	}

	OwnerMovement = PawnOwner->GetMovementComponent();
}
