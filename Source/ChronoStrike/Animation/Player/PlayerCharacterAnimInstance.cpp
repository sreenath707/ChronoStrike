#include "ChronoStrike/Animation/Player/PlayerCharacterAnimInstance.h"
#include "ChronoStrike/Characters/Player/ChronoPlayerCharacter.h"

void UPlayerCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	playerCharacter = Cast<AChronoPlayerCharacter>(Character);
}
