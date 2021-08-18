// Fill out your copyright notice in the Description page of Project Settings.


#include "HFFTestAssetFactory.h"
#include "HFFTestAsset.h"
#include "AssetTypeCategories.h"

#define LOCTEXT_NAMESPACE "HFFTest"

UHFFTestAssetFactory::UHFFTestAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;//true if the associated editor should be opened after creating a new object
	SupportedClass = UHFFTestAsset::StaticClass();
}


UObject* UHFFTestAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name,
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UHFFTestAsset* CreatedAsset = NewObject<UHFFTestAsset>(InParent, Class, Name, Flags | RF_Transactional);
	return CreatedAsset;
}

uint32 UHFFTestAssetFactory::GetMenuCategories() const
{
	//return EAssetTypeCategories::Misc;//Misc‘”œÓ¿‡±
	return EAssetTypeCategories::Animation;
}
#undef LOCTEXT_NAMESPACE