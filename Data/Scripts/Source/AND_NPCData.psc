ScriptName AND_NPCData extends Quest

Int Function RegisterPermanentFemale(Actor akFemale) Global Native
Function DeleteFemale(Actor akFemale) Global Native
Function ResetFemale(Actor akFemale) Global Native
Function TweakFemale(Actor akFemale, Int StrictRank, Int TopRank, Int BottomRank, Int MinimumStrict, Int MinimumTop, Int MinimumBottom, Int Shyness, Bool Shameless, Bool Corrupt, Bool MakeDefault, Bool Strict, Bool UpgradeBlocked, Float CurrentGameTime) Global Native
Function ResetAllFemales() Global Native
Function DeleteAllFemales() Global Native
Int Function RemovePermanent(Actor akFemale) Global Native
Function RemovePermanentAtIndex(Int PermanentIndex) Global Native