// Copyright zosiu. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class AROTarget : TargetRules
{
	public AROTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new string[] { "ARO" });
	}
}
