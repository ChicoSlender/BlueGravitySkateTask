// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleJumpTrigger.generated.h"

class URotatingMovementComponent;
class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class BLUEGRAVITYSKATETASK_API AObstacleJumpTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	AObstacleJumpTrigger();

	int GetGrantedPoints() const { return GrantedPoints; }
	
protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> Mesh;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USphereComponent> Collider;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<URotatingMovementComponent> RotatingMovement;

	UPROPERTY(EditAnywhere)
	int GrantedPoints;
};
