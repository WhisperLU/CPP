// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "UserAsset.h"
#include "MyFactory.generated.h"

/**
 * 
 */
UCLASS()
class TEST426CPP_API UMyFactory : public UFactory
{
	GENERATED_BODY()

public:
	UMyFactory();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
 
	virtual bool ShouldShowInNewMenu() const override;


};
