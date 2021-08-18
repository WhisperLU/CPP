// Fill out your copyright notice in the Description page of Project Settings.
//�����Զ�����Դ����
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
	// UFactory interface  FactoryCreateNew���ڴ�������Դ
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
		UObject* Context, FFeedbackContext* Warn) override;

	//GetMenuCategories������Դ�ķ���
	virtual uint32 GetMenuCategories() const override;
	// End of UFactory interface

};
