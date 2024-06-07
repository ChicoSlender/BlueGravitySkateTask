#include "MainMenu/MainMenuPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void AMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	AActor* Camera = UGameplayStatics::GetActorOfClass(this, ACameraActor::StaticClass());

	SetViewTarget(Camera);

	if (MainMenuWidgetClass != nullptr)
	{
		UUserWidget* MainMenuWidget = CreateWidget(this, MainMenuWidgetClass);
		MainMenuWidget->AddToViewport();
	}

	if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		EnhancedInputSubsystem->AddMappingContext(InputMapping, 0);
	}
}

void AMainMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInput->BindAction(StartInput, ETriggerEvent::Started, this, &AMainMenuPlayerController::HandleStartInput);
}

void AMainMenuPlayerController::HandleStartInput()
{
	UGameplayStatics::OpenLevel(this, GameLevelName);
}
