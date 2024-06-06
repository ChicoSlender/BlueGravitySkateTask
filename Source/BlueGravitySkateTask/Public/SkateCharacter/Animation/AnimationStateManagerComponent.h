#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimationStateManagerComponent.generated.h"

UENUM(BlueprintType)
enum EAnimationState
{
	ONGROUND	UMETA(DisplayName="On Ground"),
	JUMPING		UMETA(DisplayName="Jumping"),
	FALLING		UMETA(DisplayName="Falling"),
};

class ACharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLUEGRAVITYSKATETASK_API UAnimationStateManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAnimationStateManagerComponent();

	UFUNCTION(BlueprintPure) EAnimationState GetCurrentState() const { return CurrentState; }

	void OnJump();
	void OnJumpStop();
	void OnLanding();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	EAnimationState CurrentState;
	ACharacter* CharacterOwner;
};
