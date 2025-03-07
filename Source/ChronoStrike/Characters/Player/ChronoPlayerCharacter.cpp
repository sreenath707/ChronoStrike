#include "ChronoStrike/Characters/Player/ChronoPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ChronoStrike/Input/ChronoEnhancedInputComponent.h"
#include "ChronoStrike/GameplayTags/ChronoGameplayTags.h"
#include "EnhancedInputSubsystems.h"
#include "ChronoStrike/AbilitySystem/ChronoAbilitySystemComponent.h"
#include "ChronoStrike/DataAssets/StartupAbilities/HeroStartupAbilitiesDataAsset.h"

AChronoPlayerCharacter::AChronoPlayerCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	AbilitySystemComponent = CreateDefaultSubobject<UChronoAbilitySystemComponent>("AbilitySystemComponent");
	CombatComponent = CreateDefaultSubobject<UCombatComponent>("Combat Component");

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;
	SpringArm->bUsePawnControlRotation = true;

	UCharacterMovementComponent* characterMovment = GetCharacterMovement();
	characterMovment->bOrientRotationToMovement = false;
}

void AChronoPlayerCharacter::SetupPlayerInputComponent(UInputComponent* inputComponent)
{
	APlayerController* controller = Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(controller->GetLocalPlayer());
	check(subsystem);
	subsystem->AddMappingContext(inputConfig->inputMappingContext, 0);
	UChronoEnhancedInputComponent* chronoInputComponent = Cast<UChronoEnhancedInputComponent>(inputComponent);
	checkf(chronoInputComponent, TEXT("Input component is not setup properly"));
	chronoInputComponent->BindActionByTag(inputConfig, ChronoGameplayTags::Input_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	chronoInputComponent->BindActionByTag(inputConfig, ChronoGameplayTags::Input_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
	chronoInputComponent->BindAbilityActions(inputConfig, ETriggerEvent::Started, this, &ThisClass::Input_AbilityStart);
	chronoInputComponent->BindAbilityActions(inputConfig, ETriggerEvent::Completed, this, &ThisClass::Input_AbilityEnd);
}

void AChronoPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	checkf(StartupAbilities, TEXT("Startup Abilities not assigned for player"));
	StartupAbilities->GiveAbilities(AbilitySystemComponent, 0);
}

void AChronoPlayerCharacter::PossessedBy(AController* controller)
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AChronoPlayerCharacter::Input_Move(const FInputActionValue& inputActionValue)
{
	FVector2D input = inputActionValue.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector() * input.Y);
	AddMovementInput(GetActorRightVector() * input.X);
}

void AChronoPlayerCharacter::Input_Look(const FInputActionValue& inputActionValue)
{
	FVector2D input = inputActionValue.Get<FVector2D>();
	AddControllerYawInput(input.X);
	AddControllerPitchInput(-input.Y);
}

void AChronoPlayerCharacter::Input_AbilityStart(FGameplayTag inputTag)
{
	for (FGameplayAbilitySpec abilitySpec : AbilitySystemComponent->GetActivatableAbilities())
	{
		if (abilitySpec.DynamicAbilityTags.HasTagExact(inputTag))
		{
			if (!abilitySpec.IsActive())
			{
				AbilitySystemComponent->TryActivateAbility(abilitySpec.Handle);
			}
		}
	}
}

void AChronoPlayerCharacter::Input_AbilityEnd(FGameplayTag inputTag)
{
	for (FGameplayAbilitySpec abilitySpec : AbilitySystemComponent->GetActivatableAbilities())
	{
		if (abilitySpec.DynamicAbilityTags.HasTagExact(inputTag))
		{
			if (abilitySpec.IsActive() && abilitySpec.DynamicAbilityTags.HasTag(ChronoGameplayTags::Input_Held))
			{
				AbilitySystemComponent->CancelAbilityHandle(abilitySpec.Handle);
			}
		}
	}
}

