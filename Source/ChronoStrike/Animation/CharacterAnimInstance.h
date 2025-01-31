#pragma once

#include "CoreMinimal.h"
#include "ChronoStrike/Animation/ChronoAnimInstanceBase.h"
#include "CharacterAnimInstance.generated.h"

class AChronoCharacterBase;

/**
 * 
 */
UCLASS()
class CHRONOSTRIKE_API UCharacterAnimInstance : public UChronoAnimInstanceBase
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadOnly)
	AChronoCharacterBase* Character;
public:
	virtual void NativeInitializeAnimation()override;
};
