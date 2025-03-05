// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ChronoStrike/Characters/ChronoCharacterBase.h"
#include "ChronoGameplayAbilityBase.generated.h"


UENUM(BlueprintType)
enum class EAbilityActivationPolicy : UINT8
{
	AAP_Given,
	AAP_Triggered
};

/**
 * 
 */
UCLASS()
class CHRONOSTRIKE_API UChronoGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)override;
	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EAbilityActivationPolicy abilityActivationPolicy = EAbilityActivationPolicy::AAP_Triggered;
};
