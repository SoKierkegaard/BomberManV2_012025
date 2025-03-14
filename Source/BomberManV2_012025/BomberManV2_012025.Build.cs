// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BomberManV2_012025 : ModuleRules
{
	public BomberManV2_012025(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
