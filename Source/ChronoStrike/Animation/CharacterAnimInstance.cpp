#include "ChronoStrike/Animation/CharacterAnimInstance.h"
#include "ChronoStrike/Characters/ChronoCharacterBase.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Character = Cast<AChronoCharacterBase>(TryGetPawnOwner());
}
