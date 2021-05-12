// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionCharacter.h"

// Sets default values
AActionCharacter::AActionCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AActionCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AActionCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AActionCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Horizontal",this,&AActionCharacter::HorizontalMove);
	InputComponent->BindAxis("Vertical",this,&AActionCharacter::VerticalMove);
}
 void AActionCharacter::HorizontalMove(float value)
 {
	 if (value)
	 {
		 AddMovementInput(GetActorRightVector(),value);
	 }
 }

void AActionCharacter::VerticalMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorForwardVector(),value);
	}
}
