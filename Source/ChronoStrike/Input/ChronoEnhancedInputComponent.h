// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "NativeGameplayTags.h"
#include "ChronoStrike/DataAssets/InputConfigDataAsset.h"
#include "ChronoEnhancedInputComponent.generated.h"

class UInputConfigDataAsset;

/**
 * 
 */
UCLASS()
class CHRONOSTRIKE_API UChronoEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	template<class userObject,class callbackFn>
	FORCEINLINE void BindActionByTag(UInputConfigDataAsset* inputConfig, FGameplayTag inputTag, ETriggerEvent triggerEvent, userObject* object, callbackFn fn)
	{
		check(inputConfig);
		UInputAction* inputAction = inputConfig->FindActionByTag(inputTag);
		BindAction(inputAction, triggerEvent, object, fn);
	}

	template<class userObject,class callbackFn>
	FORCEINLINE void BindAbilityActions(UInputConfigDataAsset* inputConfig, ETriggerEvent triggerEvent, userObject* object, callbackFn fn)
	{
		check(inputConfig);
		for (FInputActionTagMap actionMap : inputConfig->AbilityInputActions)
		{
			if (actionMap.InputAction && actionMap.InputTag.IsValid())
			{
				BindAction(actionMap.InputAction, triggerEvent, object, fn, actionMap.InputTag);
			}
		}
	}
};
