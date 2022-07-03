Route3_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route3_OnLoad
	.byte 0


Route3_OnLoad::
	compare VAR_STORY_PROGRESS, 15
	goto_if_gt Route3_OnLoad_1
	return

Route3_OnLoad_1:
	setflag FLAG_TEMP_3
	return


Route3_Grunts::
	lock
	msgbox Route3_EarlyGrunt
	release
	end


Route3_EarlyGrunt::
	.string "Don't even try to get through! We have\n"
	.string "this place surrounded!$"
