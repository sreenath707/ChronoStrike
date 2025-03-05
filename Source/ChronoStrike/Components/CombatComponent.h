#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChronoStrike/Props/Weapons/Guns/GunBase.h"
#include "CombatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHRONOSTRIKE_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCombatComponent();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere)
	 TSubclassOf<AGunBase> DefaultGunClass;
	UPROPERTY(EditAnyWhere)
	AGunBase* EquippedGun;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void EquipDefaultWeapon();
		
};
