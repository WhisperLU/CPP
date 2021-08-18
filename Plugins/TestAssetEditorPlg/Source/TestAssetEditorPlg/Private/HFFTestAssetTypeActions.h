// Fill out your copyright notice in the Description page of Project Settings.
//用于资源的表现样式等  4.25引擎之后需要自定义这个类
#pragma once
#include "AssetTypeActions_Base.h"
//#include "CoreMinimal.h"

/**
 * 
 */
class HFFTestAssetTypeActions : public FAssetTypeActions_Base
{
public:

	//Asset的名字
	virtual FText GetName() const override;
	//Asset图标的颜色
	virtual FColor GetTypeColor() const override;
	//Asset的UObject是什么
	virtual UClass* GetSupportedClass() const override;
	//Asset所属的分类
	virtual uint32 GetCategories() override;

	//在AssetTypeActions的OpenAssetEditor中指定编辑器
	//重载指定编辑器,打开编辑器，出现新创建的编辑器slate
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;

};
