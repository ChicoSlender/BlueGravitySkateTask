#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "SkateCharacter.generated.h"

class UAnimationStateManagerComponent;
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

	UFUNCTION(BlueprintPure) UAnimationStateManagerComponent* GetAnimationStateManager() const { return AnimationStateManager.Get(); }
	
	void Turn(const float TurnValue);
	void Slowdown(const float ScaleValue);
	void PushSkateboard();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void OnJumped_Implementation() override;
	virtual void Landed(const FHitResult& Hit) override;

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> SkateboardMesh;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCameraComponent> CameraComponent;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCapsuleComponent> SkateTrigger;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USkateboardThrusterComponent> SkateboardThruster;
	
	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<UAnimationStateManagerComponent> AnimationStateManager;

	UPROPERTY(EditDefaultsOnly, Category="SkateMovement")
	float SpeedUpRate;

	UPROPERTY(EditDefaultsOnly, Category="SFX")
	TObjectPtr<USoundBase> PointsScoredSfx;
	
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void HandleSkateboardBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void PlayPointsScoredSfx();
};
