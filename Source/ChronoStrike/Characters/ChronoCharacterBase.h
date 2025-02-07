// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ChronoCharacterBase.generated.h"

class UChronoAbilitySystemComponent;

UCLASS()
class CHRONOSTRIKE_API AChronoCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AChronoCharacterBase();

protected:
	UChronoAbilitySystemComponent* AbilitySystemComponent;

public:	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent()const override;
};
