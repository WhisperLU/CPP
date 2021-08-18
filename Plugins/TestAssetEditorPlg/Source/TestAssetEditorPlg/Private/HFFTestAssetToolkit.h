// Fill out your copyright notice in the Description page of Project Settings.
//�����Զ�����Դ�ı༭������
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

	//��ʼ������AssetTypeActions::OpenAssetEditor�е���
	void Initialize(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, class UHFFTestAsset* Asset);

	//ע��Tab
	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;

	//����TestTabʱ����
	TSharedRef<SDockTab> SpawnTestTab(const FSpawnTabArgs& Args);

	

private:

	static const FName TestTabId;//Tab��ID

};
