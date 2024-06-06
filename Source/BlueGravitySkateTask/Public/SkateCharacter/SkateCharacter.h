#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SkateCharacter.generated.h"

class UCameraComponent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPushDelegateSignature);

class USpringArmComponent;

UCLASS()
class BLUEGRAVITYSKATETASK_API ASkateCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASkateCharacter();

	UPROPERTY(BlueprintAssignable) FPushDelegateSignature OnPushEvent; 
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> SkateboardMesh;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCameraComponent> CameraComponent;
	
	virtual void BeginPlay() override;
};
