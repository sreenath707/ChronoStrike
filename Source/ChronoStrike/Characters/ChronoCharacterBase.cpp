#include "ChronoStrike/Characters/ChronoCharacterBase.h"
#include "ChronoStrike/AbilitySystem/ChronoAbilitySystemComponent.h"

AChronoCharacterBase::AChronoCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* AChronoCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
