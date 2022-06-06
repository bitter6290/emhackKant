Route4_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route4_OnLoad
	.byte 0


Route4_OnLoad::
	compare VAR_STORY_PROGRESS, 15
	goto_if_gt Route4_OnLoad_2
Route4_OnLoad_1:
	end

Route4_OnLoad_2:
	setflag FLAG_TEMP_3
	goto Route4_OnLoad_1


Route4_Hiker::
	lock
	msgbox Route4_Hiker_Text_0
	release
	end


Route4_Hiker_Text_0:
	.string "Over or through, over or through, over\n"
	.string "or through...$"
