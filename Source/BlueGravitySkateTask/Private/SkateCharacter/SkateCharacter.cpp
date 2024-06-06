#include "SkateCharacter/SkateCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "SkateCharacter/SkateboardThrusterComponent.h"
#include "SkateCharacter/SkateCharacterMovementComponent.h"


ASkateCharacter::ASkateCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass(CharacterMovementComponentName, USkateCharacterMovementComponent::StaticClass()))
{
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	SkateboardMesh = CreateDefaultSubobject<UStaticMeshComponent>("SkateboardMesh");
	SkateboardMesh->SetupAttachment(RootComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	SkateboardThruster = CreateDefaultSubobject<USkateboardThrusterComponent>("SkateboardThruster");
}

void ASkateCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASkateCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASkateCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASkateCharacter::Turn(const float TurnValue)
{
	SkateboardThruster->Turn(TurnValue);
}

void ASkateCharacter::StartSlowingDown()
{
	SkateboardThruster->Stop();
}

void ASkateCharacter::StopSlowingDown()
{
	SkateboardThruster->Start();
}
