// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestAssetEditorPlg : ModuleRules
{
	public TestAssetEditorPlg(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		//以下变量之前的Public和Private通常表示与本模块中的public文件夹还是private文件夹相关。
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				//一般不用配置，默认启用，Public文件夹中都为暴露给其它模块的包含目录。
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
				//表示本模块中Private文件夹中哪些文件夹是包含目录。
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"NewPluginModule"
				// ... add other public dependencies that you statically link with here ...
				//这些是我们的public文件夹所需的模块。自动包含所依赖模块的public/private的包含目录。需要链接。
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UnrealEd"//factory类必须要包含这个模块
				// ... add private dependencies that you statically link with here ...	
				//私有依赖模块名称列表。 这些是我们的private文件夹代码所依赖的模块，但我们的public文件中不会有对这些模块的依赖，需要链接。
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
