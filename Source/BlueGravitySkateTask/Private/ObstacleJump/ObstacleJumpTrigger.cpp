#include "ObstacleJump/ObstacleJumpTrigger.h"

#include "Components/SphereComponent.h"
#include "GameFramework/RotatingMovementComponent.h"

AObstacleJumpTrigger::AObstacleJumpTrigger()
{
	PrimaryActorTick.bCanEverTick = false;

	Collider = CreateDefaultSubobject<USphereComponent>("Collider");
	SetRootComponent(Collider);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovement");

	GrantedPoints = 30;
}
