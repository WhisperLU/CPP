// Copyright Epic Games, Inc. All Rights Reserved.
//游戏的编译配置文件，描述游戏依赖的Module
using UnrealBuildTool;
using System.Collections.Generic;

public class Test426CPPTarget : TargetRules
{
	public Test426CPPTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		//ExtraModuleNames.Add("Test426CPP");
		ExtraModuleNames.AddRange(new string[] { "Test426CPP", "XmlToJson" });
	}
}
