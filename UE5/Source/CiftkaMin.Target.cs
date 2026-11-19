using UnrealBuildTool;
using System.Collections.Generic;
public class CiftkaMinTarget : TargetRules
{
    public CiftkaMinTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;
        ExtraModuleNames.Add("CiftkaMin");
    }
}