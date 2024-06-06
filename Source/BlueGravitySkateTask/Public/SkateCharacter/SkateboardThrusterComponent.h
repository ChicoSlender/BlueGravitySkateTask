#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkateboardThrusterComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BLUEGRAVITYSKATETASK_API USkateboardThrusterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USkateboardThrusterComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Stop();
	void Start();
	void Turn(float Scale);

protected:
	APawn* PawnOwner;
	UPawnMovementComponent* OwnerMovement;
	bool bStopMovement;
	float MaxTurnRate;
	float TurnInput;
	
	virtual void BeginPlay() override;
};
