#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuPlayerController.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class BLUEGRAVITYSKATETASK_API AMainMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputMappingContext> InputMapping;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> StartInput;

	UPROPERTY(EditDefaultsOnly, Category="Maps")
	FName GameLevelName;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
	
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void HandleStartInput();
};
