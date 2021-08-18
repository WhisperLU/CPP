// Copyright Epic Games, Inc. All Rights Reserved.
//�༭�����������ļ�������������Module
using UnrealBuildTool;
using System.Collections.Generic;

public class Test426CPPEditorTarget : TargetRules
{
	public Test426CPPEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		//ExtraModuleNames.Add("Test426CPP");
		ExtraModuleNames.AddRange(new string[] { "Test426CPP", "XmlToJson" });
	}
}
