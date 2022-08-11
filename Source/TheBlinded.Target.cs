// The Blinded Game by XTOR Team, All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TheBlindedTarget : TargetRules
{
	public TheBlindedTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "TheBlinded" } );
	}
}
