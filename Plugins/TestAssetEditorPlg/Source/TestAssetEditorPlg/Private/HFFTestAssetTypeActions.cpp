// Fill out your copyright notice in the Description page of Project Settings.


#include "HFFTestAssetTypeActions.h"
#include "HFFTestAsset.h"
#include "HFFTestAssetToolkit.h"

#define LOCTEXT_NAMESPACE "HFFTest"

//Asset������
FText HFFTestAssetTypeActions::GetName() const
{
	//return LOCTEXT("HFFTestAssetTypeActions", "HFFTestAsset");
	return LOCTEXT("HFFTestAssetTypeActions", "Hello");
}
//Assetͼ�����ɫ
FColor HFFTestAssetTypeActions::GetTypeColor() const
{
	return FColor(255, 0, 255);
}
//Asset��UObject��ʲô
UClass* HFFTestAssetTypeActions::GetSupportedClass() const
{
	return UHFFTestAsset::StaticClass();
}
//Asset�����ķ���
uint32 HFFTestAssetTypeActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}

void HFFTestAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{

	EToolkitMode::Type Mode = EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto Asset = Cast<UHFFTestAsset>(*ObjIt);
		if (Asset != NULL)
		{
			TSharedRef< HFFTestAssetToolkit > NewToolkit(new HFFTestAssetToolkit());
			NewToolkit->Initialize(Mode, EditWithinLevelEditor, Asset);
		}
	}
}

#undef LOCTEXT_NAMESPACE
