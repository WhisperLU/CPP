// Fill out your copyright notice in the Description page of Project Settings.
//用于自定义资源创建
#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "HFFTestAssetFactory.generated.h"

/**
 * 
 */
UCLASS(config = Editor)
class UHFFTestAssetFactory : public UFactory
{
	GENERATED_BODY()
public:
	UHFFTestAssetFactory(const FObjectInitializer& ObjectInitializer);
public:
	// UFactory interface  FactoryCreateNew用于创建新资源
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
		UObject* Context, FFeedbackContext* Warn) override;

	//GetMenuCategories用于资源的分类
	virtual uint32 GetMenuCategories() const override;
	// End of UFactory interface

};
