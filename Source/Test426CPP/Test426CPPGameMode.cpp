// Copyright Epic Games, Inc. All Rights Reserved.

#include "Test426CPPGameMode.h"
#include "Test426CPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATest426CPPGameMode::ATest426CPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
