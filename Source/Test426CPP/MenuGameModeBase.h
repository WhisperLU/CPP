// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MenuGameModeBase.generated.h"

/**
 * 
 */
 
 class NewClass
 {
 public:
 	int MyValues;
 };

 
UCLASS()
class TEST426CPP_API AMenuGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMenuGameModeBase();
	virtual ~AMenuGameModeBase() override;//把析构函数定义为虚函数是个很好的选择

	UFUNCTION(BlueprintCallable,Category = "NewFunction")
	void NewFunc();
	
};
