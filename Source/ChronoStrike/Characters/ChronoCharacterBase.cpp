// Fill out your copyright notice in the Description page of Project Settings.


#include "ChronoStrike/Characters/ChronoCharacterBase.h"

// Sets default values
AChronoCharacterBase::AChronoCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChronoCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChronoCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AChronoCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

