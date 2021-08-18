// Copyright Epic Games, Inc. All Rights Reserved.//��Ҫ��������Module�ı��뻷����

using UnrealBuildTool;

public class XmlToJson : ModuleRules
{
	public XmlToJson(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "XmlParser", "Json", "JsonUtilities" });
		PrivateDependencyModuleNames.AddRange(new string[]{"Slate","SlateCore"});
	}
}
