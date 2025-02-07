// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChronoStrike/Characters/ChronoCharacterBase.h"
#include <GameplayTagContainer.h>
#include "ChronoPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputConfigDataAsset;
class UHeroStartupAbilitiesDataAsset;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class CHRONOSTRIKE_API AChronoPlayerCharacter : public AChronoCharacterBase
{
	GENERATED_BODY()
public:
	AChronoPlayerCharacter();

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCameraComponent> Camera;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputConfigDataAsset> inputConfig;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UHeroStartupAbilitiesDataAsset> StartupAbilities;

	virtual void SetupPlayerInputComponent(UInputComponent* inputComponent)override;
	virtual void BeginPlay()override;

private:
	void Input_Move(const FInputActionValue& inputActionValue);
	void Input_Look(const FInputActionValue& inputActionValue);
	void Input_AbilityStart(FGameplayTag inputTag);
};
