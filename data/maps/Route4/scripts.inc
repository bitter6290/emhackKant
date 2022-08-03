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


Route4_Artist::
	lock
	release
	end


Route4_Hiker::
	lock
	compare VAR_STORY_PROGRESS, 16
	goto_if_eq Route4_Hiker_2
	msgbox Route4_Hiker_Text_2
Route4_Hiker_1:
	release
	end

Route4_Hiker_2:
	msgbox Route4_Hiker_Text_0
	faceplayer
	playse SE_PIN
	applymovement 2, Exclam
	waitmovement 2
	release
	msgbox Route4_Hiker_Text_1
	giveitem ITEM_REPEL, 5
	setvar VAR_STORY_PROGRESS, 17
	goto Route4_Hiker_1


Route4_Hiker_Text_0:
	.string "Over or through, over or through, over\n"
	.string "or through...$"

Route4_Hiker_Text_1:
	.string "Ah! Who are you? You don't have the look\n"
	.string "of a hiker about you.\l"
	.string "These roads are dangerous, you know.\l"
	.string "Take some of these and you'll be better\l"
	.string "prepared.$"

Route4_Hiker_Text_2:
	.string "I've taken this route plenty of times\n"
	.string "before, but it's a real Morton's choice.\l"
	.string "You're either lost in a cave or dealing\l"
	.string "with those blasted rocks!$"
