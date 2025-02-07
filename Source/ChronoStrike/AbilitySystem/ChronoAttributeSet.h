// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "ChronoAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class CHRONOSTRIKE_API UChronoAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UChronoAttributeSet();

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UChronoAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UChronoAttributeSet, CurrentHealth);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData DefencePower;
	ATTRIBUTE_ACCESSORS(UChronoAttributeSet, DefencePower);

	UPROPERTY(BlueprintReadOnly)
	FGameplayAttributeData DamageTaken;
	ATTRIBUTE_ACCESSORS(UChronoAttributeSet, DamageTaken);
};
