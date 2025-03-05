#include "ChronoStrike/Props/Weapons/WeaponBase.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;
	weaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon Mesh");
	weaponMesh->SetupAttachment(RootComponent);
}

