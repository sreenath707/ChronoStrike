// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StartupAbilitiesDataAsset.generated.h"

class UChronoGameplayAbilityBase;
class UChronoAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class CHRONOSTRIKE_API UStartupAbilitiesDataAsset : public UDataAsset
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TArray<TSubclassOf<UChronoGameplayAbilityBase>> StartupAbilities;

public:
	virtual void GiveAbilities(UChronoAbilitySystemComponent* acs, int ApplyLevel);
};
