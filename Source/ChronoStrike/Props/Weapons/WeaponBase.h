#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class CHRONOSTRIKE_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeaponBase();
protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	USkeletalMeshComponent* weaponMesh;

};
