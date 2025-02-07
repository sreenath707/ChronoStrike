#include "ChronoStrike/AbilitySystem/ChronoGameplayAbilityBase.h"
#include "ChronoGameplayAbilityBase.h"
#include "AbilitySystemComponent.h"

void UChronoGameplayAbilityBase::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);
	if (abilityActivationPolicy == EAbilityActivationPolicy::AAP_Given)
	{
		ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
	}
}

void UChronoGameplayAbilityBase::OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnRemoveAbility(ActorInfo, Spec);
	if (abilityActivationPolicy == EAbilityActivationPolicy::AAP_Given)
	{
		ActorInfo->AbilitySystemComponent->ClearAbility(Spec.Handle);
	}
}
