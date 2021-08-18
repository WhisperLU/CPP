// Copyright Epic Games, Inc. All Rights Reserved.//主要描述所在Module的编译环境。

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
