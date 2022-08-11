// The Blinded Game by XTOR Team, All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class TheBlindedEditorTarget : TargetRules
{
	public TheBlindedEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "TheBlinded" } );
	}
}
