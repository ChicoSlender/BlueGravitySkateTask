#include "SkateCharacter/SkateCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "SkateCharacter/SkateboardThrusterComponent.h"
#include "SkateCharacter/SkateCharacterMovementComponent.h"
#include "SkateCharacter/Animation/AnimationStateManagerComponent.h"


ASkateCharacter::ASkateCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass(CharacterMovementComponentName, USkateCharacterMovementComponent::StaticClass()))
{
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	JumpMaxHoldTime = 0.2f;

	SpeedUpRate = 0.3f;

	SkateboardMesh = CreateDefaultSubobject<UStaticMeshComponent>("SkateboardMesh");
	SkateboardMesh->SetupAttachment(RootComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	SkateboardThruster = CreateDefaultSubobject<USkateboardThrusterComponent>("SkateboardThruster");
	
	AnimationStateManager = CreateDefaultSubobject<UAnimationStateManagerComponent>("AnimationStateManager");
}

void ASkateCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASkateCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ASkateCharacter::OnJumped_Implementation()
{
	Super::OnJumped_Implementation();

	AnimationStateManager->OnJump();
}

void ASkateCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);

	AnimationStateManager->OnLanding();
}

void ASkateCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASkateCharacter::Turn(const float TurnValue)
{
	SkateboardThruster->Turn(TurnValue);
}

void ASkateCharacter::Slowdown(const float ScaleValue)
{
	SkateboardThruster->SlowDown(ScaleValue);
}

void ASkateCharacter::PushSkateboard()
{
	SkateboardThruster->SpeedUp(SpeedUpRate);
	OnPushEvent.Broadcast();
}
