// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestAssetEditorPlg.h"
//包含模块
#include "AssetToolsModule.h"
#include "HFFTestAssetTypeActions.h"


//定义创建本地化的文本片段
#define LOCTEXT_NAMESPACE "HFFTest"
//模块加载时
void FTestAssetEditorPlgModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	//模块启动时，需要注册Asset，如果不注册，资源创建失败
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked< FAssetToolsModule >("AssetTools").Get();
	AssetTools.RegisterAssetTypeActions(MakeShareable(new HFFTestAssetTypeActions()));
}
//模块卸载时
void FTestAssetEditorPlgModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

//结尾取消定义
#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestAssetEditorPlgModule, TestAssetEditorPlg)