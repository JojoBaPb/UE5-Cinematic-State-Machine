using UnrealBuildTool;
using System.Collections.Generic;

public class CinematicMenuEditorTarget : TargetRules
{
    public CinematicMenuEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;
        ExtraModuleNames.Add("CinematicMenu");
    }
}