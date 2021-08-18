// Copyright Epic Games, Inc. All Rights Reserved.//��Ҫ��������Module�ı��뻷����

using UnrealBuildTool;

public class Test426CPP : ModuleRules
{
	public Test426CPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","XmlToJson" });
		PrivateDependencyModuleNames.AddRange(new string[]{"Slate","SlateCore"});
	}
}
