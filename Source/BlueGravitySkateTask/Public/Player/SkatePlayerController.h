#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "SkatePlayerController.generated.h"

class ASkateCharacter;
class UInputMappingContext;
class UInputAction;

UCLASS()
class BLUEGRAVITYSKATETASK_API ASkatePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASkatePlayerController();
	
protected:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputMappingContext> InputMapping;
	
	UPROPERTY(EditDefaultsOnly, Category="Input|Actions")
	TObjectPtr<UInputAction> SlowDownInput;
	UPROPERTY(EditDefaultsOnly, Category="Input|Actions")
	TObjectPtr<UInputAction> TurnInput;
	UPROPERTY(EditDefaultsOnly, Category="Input|Actions")
	TObjectPtr<UInputAction> JumpInput;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	float SlowdownMinTriggerValue;
	
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* NewPawn) override;

private:
	ASkateCharacter* PossessedSkateCharacter;
	
	void HandleTurnInput(const FInputActionValue& InputActionValue);
	void HandleSlowDownInputRelease();
	void HandleSlowDownInputTrigger(const FInputActionValue& InputActionValue);
	void HandleJumpInputPress();
	void HandleJumpInputRelease();
};
