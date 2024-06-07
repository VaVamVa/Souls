// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Souls : ModuleRules
{
	public Souls(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });

		PublicIncludePaths.Add(ModuleDirectory);
	}
}
