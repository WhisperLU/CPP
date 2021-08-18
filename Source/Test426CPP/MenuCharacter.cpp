// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuCharacter.h"

// Sets default values
AMenuCharacter::AMenuCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMenuCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMenuCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMenuCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AMenuCharacter::DelayAA(UObject* WorldContextObject, float Duration, FLatentActionInfo LatentInfo)
{
}

void AMenuCharacter::DelayBB(UObject* WorldContextObject, float Duration, FLatentActionInfo LatentInfo)
{
}

void AMenuCharacter::EvaluateCurveTableRow(UCurveTable* CurveTable, FName RowName, float InXY, TEnumAsByte<EEvaluateCurveTableResult::Type>& OutResult, float& OutXY)
{
}

void AMenuCharacter::EvaluateCurveTableRowNew(UCurveTable* CurveTable, FName RowName, float InXY, TEnumAsByte<EEvaluateCurveTableResult::Type>& OutResult, float& OutXY)
{
}




