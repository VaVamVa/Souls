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
            "AnimationCore", "AnimGraphRuntime",
            "AIModule",
            "GameplayAbilities", "GameplayTags", "GameplayTasks"
        });

		PublicIncludePaths.Add(ModuleDirectory);

        // MyProject 폴더 아래의 모든 하위 폴더 경로 추가
        PublicIncludePaths.AddRange(
            Directory.GetDirectories(ModuleDirectory, "*_Manual.h", SearchOption.AllDirectories)
        );

    }
}
