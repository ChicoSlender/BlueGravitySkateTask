#include "Player/SkatePlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "SkateCharacter/SkateCharacter.h"

ASkatePlayerController::ASkatePlayerController()
{
	SlowdownMinTriggerValue = 0.1f;
	PossessedSkateCharacter = nullptr;
}

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
	EnhancedInput->BindAction(SlowDownInput, ETriggerEvent::Triggered, this, &ASkatePlayerController::HandleSlowDownInputTrigger);
	EnhancedInput->BindAction(SlowDownInput, ETriggerEvent::Completed, this, &ASkatePlayerController::HandleSlowDownInputRelease);
	EnhancedInput->BindAction(JumpInput, ETriggerEvent::Started, this, &ASkatePlayerController::HandleJumpInputPress);
	EnhancedInput->BindAction(JumpInput, ETriggerEvent::Completed, this, &ASkatePlayerController::HandleJumpInputRelease);
	EnhancedInput->BindAction(PushInput, ETriggerEvent::Triggered, this, &ASkatePlayerController::HandlePushInput);
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

void ASkatePlayerController::HandleSlowDownInputRelease()
{
	if (PossessedSkateCharacter == nullptr)
	{
		return;
	}

	PossessedSkateCharacter->Slowdown(0.0f);
}

void ASkatePlayerController::HandleSlowDownInputTrigger(const FInputActionValue& InputActionValue)
{
	if (PossessedSkateCharacter == nullptr)
	{
		return;
	}

	float InputValue = InputActionValue.Get<float>();
	InputValue = FMath::Clamp(InputValue, 0.0f, 1.0f);

	PossessedSkateCharacter->Slowdown(InputValue);
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

void ASkatePlayerController::HandlePushInput()
{
	if (PossessedSkateCharacter == nullptr)
	{
		return;
	}

	PossessedSkateCharacter->PushSkateboard();
}
