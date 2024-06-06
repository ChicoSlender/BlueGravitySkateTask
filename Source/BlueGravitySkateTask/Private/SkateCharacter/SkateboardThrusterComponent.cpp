#include "SkateCharacter/SkateboardThrusterComponent.h"

#include "GameFramework/PawnMovementComponent.h"


USkateboardThrusterComponent::USkateboardThrusterComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	PawnOwner = nullptr;
	OwnerMovement = nullptr;
	MaxTurnRate = 2.0f;
	TurnInput = 0.0f;
	MinMovementScale = 0.15f;
}


void USkateboardThrusterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (PawnOwner == nullptr || OwnerMovement == nullptr)
	{
		return;
	}
	
	FVector MovementDirection = PawnOwner->GetActorForwardVector();
	
	MovementDirection = MovementDirection.RotateAngleAxis(MaxTurnRate * TurnInput, PawnOwner->GetActorUpVector());
	
	OwnerMovement->AddInputVector(MovementDirection * CurrentMovementScale);
	
	TurnInput = 0.0f;
}

void USkateboardThrusterComponent::Turn(float Scale)
{
	TurnInput = Scale;
}

void USkateboardThrusterComponent::SlowDown(float SlowdownScale)
{
	CurrentMovementScale = MinMovementScale * (1-SlowdownScale);
}

void USkateboardThrusterComponent::SpeedUp(float Amount)
{
	CurrentMovementScale = FMath::Min(CurrentMovementScale+Amount, 1.0f);
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
