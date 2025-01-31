// Fill out your copyright notice in the Description page of Project Settings.


#include "ChronoStrike/DataAssets/InputConfigDataAsset.h"

UInputAction* UInputConfigDataAsset::FindActionByTag(FGameplayTag inputTag)
{
	for (FInputActionTagMap inputActionTag : inputActionTagMap)
	{
		if (inputActionTag.InputTag.MatchesTag(inputTag))
		{
			return inputActionTag.InputAction;
		}
	}
	return nullptr;
}
