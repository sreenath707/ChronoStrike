#pragma once

#include "CoreMinimal.h"


UENUM(BlueprintType)
enum class EChronoAimState : uint8
{
	EAS_Idle UMETA(DisplayName = "Idle"),
	EAS_Hold UMETA(DisplayName = "Hold"),
	EAS_Aim UMETA(DisplayName = "Aim")
};
