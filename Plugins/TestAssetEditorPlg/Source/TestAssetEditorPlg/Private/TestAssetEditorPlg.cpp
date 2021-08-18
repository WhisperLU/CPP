// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestAssetEditorPlg.h"
//����ģ��
#include "AssetToolsModule.h"
#include "HFFTestAssetTypeActions.h"


//���崴�����ػ����ı�Ƭ��
#define LOCTEXT_NAMESPACE "HFFTest"
//ģ�����ʱ
void FTestAssetEditorPlgModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	//ģ������ʱ����Ҫע��Asset�������ע�ᣬ��Դ����ʧ��
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked< FAssetToolsModule >("AssetTools").Get();
	AssetTools.RegisterAssetTypeActions(MakeShareable(new HFFTestAssetTypeActions()));
}
//ģ��ж��ʱ
void FTestAssetEditorPlgModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

//��βȡ������
#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestAssetEditorPlgModule, TestAssetEditorPlg)