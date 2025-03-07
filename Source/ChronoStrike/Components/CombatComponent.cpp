#include "ChronoStrike/Components/CombatComponent.h"
#include "ChronoStrike/Characters/ChronoCharacterBase.h"

UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCombatComponent::EquipDefaultWeapon()
{
	UWorld* world = GetWorld();
	AChronoCharacterBase* playerCharacter = Cast<AChronoCharacterBase>(GetOwner());
	FActorSpawnParameters spawnParams;
	spawnParams.Instigator = playerCharacter;
	spawnParams.Owner = playerCharacter;
	check(DefaultGunClass);
	EquippedGun = world->SpawnActor<AGunBase>(DefaultGunClass, playerCharacter->GetTransform(), spawnParams);
	EquippedGun->AttachToComponent(playerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Weapon_Hand_Socket"));
}

void UCombatComponent::Aim()
{
	playerAimState = EChronoAimState::EAS_Aim;
}

void UCombatComponent::UnAim()
{
	playerAimState = EChronoAimState::EAS_Hold;
}

