// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NativeGameplayTags.h"
#include "InputConfigDataAsset.generated.h"

class UInputMappingContext;
class UInputAction;

USTRUCT(BlueprintType)
struct FInputActionTagMap {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FGameplayTag InputTag;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UInputAction* InputAction;
};

/**
 * 
 */
UCLASS()
class CHRONOSTRIKE_API UInputConfigDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UInputMappingContext* inputMappingContext;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TArray<FInputActionTagMap> inputActionTagMap;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TArray<FInputActionTagMap> AbilityInputActions;

	UInputAction* FindActionByTag(FGameplayTag inputTag);
};
