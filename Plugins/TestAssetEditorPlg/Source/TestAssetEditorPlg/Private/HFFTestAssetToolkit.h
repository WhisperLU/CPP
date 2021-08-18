// Fill out your copyright notice in the Description page of Project Settings.
//用于自定义资源的编辑器界面
#pragma once

#include "CoreMinimal.h"

#include "Toolkits/AssetEditorToolkit.h"

/**
 * 
 */
class HFFTestAssetToolkit :public FAssetEditorToolkit
{
public:
	//~ Begin IToolkit Interface
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	//~ End IToolkit Interface

	//初始化，在AssetTypeActions::OpenAssetEditor中调用
	void Initialize(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, class UHFFTestAsset* Asset);

	//注册Tab
	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;

	//生成TestTab时调用
	TSharedRef<SDockTab> SpawnTestTab(const FSpawnTabArgs& Args);

	

private:

	static const FName TestTabId;//Tab的ID

};
