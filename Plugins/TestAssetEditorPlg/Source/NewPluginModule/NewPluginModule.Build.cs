// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NewPluginModule : ModuleRules
{
	public NewPluginModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		//���±���֮ǰ��Public��Privateͨ����ʾ�뱾ģ���е�public�ļ��л���private�ļ�����ء�
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
				//һ�㲻�����ã�Ĭ�����ã�Public�ļ����ж�Ϊ��¶������ģ��İ���Ŀ¼��
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
				//��ʾ��ģ����Private�ļ�������Щ�ļ����ǰ���Ŀ¼��
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				// ... add other public dependencies that you statically link with here ...
				//��Щ�����ǵ�public�ļ��������ģ�顣�Զ�����������ģ���public/private�İ���Ŀ¼����Ҫ���ӡ�
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
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