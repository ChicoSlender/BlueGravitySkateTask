#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "SkateCharacter.generated.h"

class USkateboardThrusterComponent;
class UCameraComponent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPushDelegateSignature);

class USpringArmComponent;

UCLASS()
class BLUEGRAVITYSKATETASK_API ASkateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASkateCharacter(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintAssignable) FPushDelegateSignature OnPushEvent; 
	
	void Turn(const float TurnValue);
	void Slowdown(const float ScaleValue);
	void PushSkateboard();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> SkateboardMesh;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCameraComponent> CameraComponent;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USkateboardThrusterComponent> SkateboardThruster;

	UPROPERTY(EditDefaultsOnly, Category="SkateMovement")
	float SpeedUpRate;
	
	virtual void BeginPlay() override;
};
