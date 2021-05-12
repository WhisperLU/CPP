// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGameModeBase.h"
#include "MenuCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MenuHUD.h"
#include "MenuPlayerController.h"

AMenuGameModeBase::AMenuGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
	
}

