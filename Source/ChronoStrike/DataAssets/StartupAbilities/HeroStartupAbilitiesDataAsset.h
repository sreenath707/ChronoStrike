#pragma once

#include "CoreMinimal.h"
#include "ChronoStrike/DataAssets/StartupAbilities/StartupAbilitiesDataAsset.h"
#include "GameplayTagContainer.h"
#include "HeroStartupAbilitiesDataAsset.generated.h"


USTRUCT(BlueprintType)
struct FInputAbilityTagMap {
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FGameplayTag InputTag;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	TSubclassOf<UChronoGameplayAbilityBase> ability;
};

/**
 * 
 */
UCLASS()
class CHRONOSTRIKE_API UHeroStartupAbilitiesDataAsset : public UStartupAbilitiesDataAsset
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TArray<FInputAbilityTagMap> InputStartupAbilities;

public:
	virtual void GiveAbilities(UChronoAbilitySystemComponent* acs, int ApplyLevel)override;
};
