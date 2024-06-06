#include "Player/SkatePlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "SkateCharacter/SkateCharacter.h"

void ASkatePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		EnhancedInputSubsystem->AddMappingContext(InputMapping, 0);
	}
}

void ASkatePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInput->BindAction(TurnInput, ETriggerEvent::Triggered, this, &ASkatePlayerController::HandleTurnInput);
	EnhancedInput->BindAction(SlowDownInput, ETriggerEvent::Started, this, &ASkatePlayerController::HandleSlowDownInputPress);
	EnhancedInput->BindAction(SlowDownInput, ETriggerEvent::Completed, this, &ASkatePlayerController::HandleSlowDownInputRelease);
	EnhancedInput->BindAction(JumpInput, ETriggerEvent::Started, this, &ASkatePlayerController::HandleJumpInputPress);
	EnhancedInput->BindAction(JumpInput, ETriggerEvent::Completed, this, &ASkatePlayerController::HandleJumpInputRelease);
}

void ASkatePlayerController::OnPossess(APawn* NewPawn)
{
	Super::OnPossess(NewPawn);

	PossessedSkateCharacter = Cast<ASkateCharacter>(NewPawn);
}

void ASkatePlayerController::HandleTurnInput(const FInputActionValue& InputActionValue)
{
	if (PossessedSkateCharacter == nullptr)
	{
		return;
	}

	float InputValue = InputActionValue.Get<float>();
	PossessedSkateCharacter->Turn(InputValue);
}

void ASkatePlayerController::HandleSlowDownInputPress()
{
	if (PossessedSkateCharacter == nullptr)
	{
		return;
	}

	PossessedSkateCharacter->StartSlowingDown();
}

void ASkatePlayerController::HandleSlowDownInputRelease()
{
	if (PossessedSkateCharacter == nullptr)
	{
		return;
	}

	PossessedSkateCharacter->StopSlowingDown();
}

void ASkatePlayerController::HandleJumpInputPress()
{
	if (PossessedSkateCharacter == nullptr)
	{
		return;
	}

	PossessedSkateCharacter->Jump();
}

void ASkatePlayerController::HandleJumpInputRelease()
{
	if (PossessedSkateCharacter == nullptr)
	{
		return;
	}

	PossessedSkateCharacter->StopJumping();
}
