// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChronoStrike/Animation/CharacterAnimInstance.h"
#include "PlayerCharacterAnimInstance.generated.h"

class AChronoPlayerCharacter;

/**
 * 
 */
UCLASS()
class CHRONOSTRIKE_API UPlayerCharacterAnimInstance : public UCharacterAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly)
	AChronoPlayerCharacter* playerCharacter;
	
public:
	virtual void NativeInitializeAnimation()override;
};
