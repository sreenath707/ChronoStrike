#include "ChronoStrike/DataAssets/StartupAbilities/StartupAbilitiesDataAsset.h"
#include "ChronoStrike/AbilitySystem/ChronoGameplayAbilityBase.h"
#include "ChronoStrike/AbilitySystem/ChronoAbilitySystemComponent.h"

void UStartupAbilitiesDataAsset::GiveAbilities(UChronoAbilitySystemComponent* acs, int ApplyLevel)
{
	for (TSubclassOf<UChronoGameplayAbilityBase> ability : StartupAbilities)
	{
		FGameplayAbilitySpec abilitySpec(ability);
		abilitySpec.Level = ApplyLevel;
		abilitySpec.SourceObject = acs->GetAvatarActor();
		acs->GiveAbility(abilitySpec);
	}
}
