// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class Souls : ModuleRules
{
	public Souls(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", "CoreUObject", "Engine",
			"InputCore", "EnhancedInput",
            "AnimGraphRuntime",
            "AIModule"
        });

		PublicIncludePaths.Add(ModuleDirectory);

        // MyProject ���� �Ʒ��� ��� ���� ���� ��� �߰�
        PublicIncludePaths.AddRange(
            Directory.GetDirectories(ModuleDirectory, "*_Manual.h", SearchOption.AllDirectories)
        );

    }
}
