// The Blinded Game by XTOR Team, All Rights Reserved.

using UnrealBuildTool;

public class TheBlinded : ModuleRules
{
	public TheBlinded(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "GameplayTasks", "NavigationSystem" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Our public folders
        PublicIncludePaths.AddRange(new string[]
        {
            "TheBlinded/Public/Player",
            "TheBlinded/Public/Weapon",
            "TheBlinded/Public/Component"
        });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
