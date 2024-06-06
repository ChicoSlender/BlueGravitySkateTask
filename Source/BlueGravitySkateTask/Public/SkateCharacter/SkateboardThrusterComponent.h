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
	void Turn(float Scale);
	void SlowDown(float SlowdownScale);
	void SpeedUp(float Amount);

protected:
	UPROPERTY(EditDefaultsOnly)
	float MaxTurnRate;
	UPROPERTY(EditDefaultsOnly)
	float MinMovementScale;
	
	APawn* PawnOwner;
	UPawnMovementComponent* OwnerMovement;
	float TurnInput;
	
	virtual void BeginPlay() override;

private:
	float CurrentMovementScale;
};
