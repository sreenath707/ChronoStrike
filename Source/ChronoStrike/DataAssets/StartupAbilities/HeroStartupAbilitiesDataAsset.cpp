#include "ChronoStrike/DataAssets/StartupAbilities/HeroStartupAbilitiesDataAsset.h"
#include "ChronoStrike/AbilitySystem/ChronoGameplayAbilityBase.h"
#include "ChronoStrike/AbilitySystem/ChronoAbilitySystemComponent.h"

void UHeroStartupAbilitiesDataAsset::GiveAbilities(UChronoAbilitySystemComponent* acs, int ApplyLevel)
{
	Super::GiveAbilities(acs, ApplyLevel);
	for (FInputAbilityTagMap ability : InputStartupAbilities)
	{
		FGameplayAbilitySpec abilitySpec(ability.ability);
		abilitySpec.Level = ApplyLevel;
		abilitySpec.SourceObject = acs->GetAvatarActor();
		abilitySpec.DynamicAbilityTags.AddTag(ability.InputTag);
		acs->GiveAbility(abilitySpec);
	}
}
