PewterMineNorthHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PewterMineNorthHouse_OnLoad
	.byte 0


PewterMineNorthHouse_OnLoad::
	compare VAR_STORY_PROGRESS, 14
	goto_if_gt PewterMineNorthHouse_OnLoad_1
	return

PewterMineNorthHouse_OnLoad_1:
	setflag FLAG_TEMP_3
	end


PewterMineNorthHouse_Morgan::
	lock
	compare VAR_STORY_PROGRESS, 14
	goto_if_eq PewterMineNorthHouse_Morgan_2
PewterMineNorthHouse_Morgan_1:
	release
	end

PewterMineNorthHouse_Morgan_2:
	playse SE_PIN
	applymovement 1, PewterMine_Exclam
	waitmovement 1
	msgbox PewterMineNorthHouse_Morgan_Text_0
	applymovement 1, PewterMineNorthHouse_MorganSouth
	waitmovement 1
	msgbox PewterMineNorthHouse_Morgan_Text_1
	waitmessage
	delay 30
	msgbox PewterMineNorthHouse_Morgan_Text_2
	applymovement 1, PewterMineNorthHouse_MorganSide
	waitmovement 1
	msgbox PewterMineNorthHouse_Morgan_Text_3
	waitmessage
	delay 60
	applymovement 1, PewterMine_Exclam
	waitmovement 1
	msgbox PewterMineNorthHouse_Morgan_Text_4
	msgbox PewterMineNorthHouse_Morgan_Text_5
	applymovement 1, PewterMineNorthHouse_MorganThree
	waitmovement 1
	playse SE_PIN
	applymovement 1, PewterMine_Exclam
	waitmovement 1
	msgbox PewterMineNorthHouse_Morgan_Text_6
	applymovement 1, PewterMineNorthHouse_MorganSouth
	setflag FLAG_TEMP_3
	removeobject 1
	addvar VAR_STORY_PROGRESS, 1
	goto PewterMineNorthHouse_Morgan_1


PewterMineNorthHouse_MorganSouth:
	walk_down
	walk_down
	step_end

PewterMineNorthHouse_MorganSide:
	face_left
	face_down
	step_end

PewterMineNorthHouse_MorganThree:
	walk_left
	walk_down
	face_right
	step_end

PewterMineNorthHouse_Morgan_Text_0:
	.string "Ah!$"

PewterMineNorthHouse_Morgan_Text_1:
	.string "Are you... {PLAYER}?$"

PewterMineNorthHouse_Morgan_Text_2:
	.string "So you've left Pallet Town... Oak must\n"
	.string "have sent you.\l"
	.string "And you got caught up in all of this!\l"
	.string "How stressful...$"

PewterMineNorthHouse_Morgan_Text_3:
	.string "I'm Morgan, Professor Oak's assistant.\n"
	.string "As you might have guessed, I got\l"
	.string "trapped in here when the fighting\l"
	.string "started. And just now, that sound I\l"
	.string "heard?$"

PewterMineNorthHouse_Morgan_Text_4:
	.string "An explosion? Really!?$"

PewterMineNorthHouse_Morgan_Text_5:
	.string "I need to get out of here... And you\n"
	.string "should too, {PLAYER}. Who knows what\l"
	.string "the impact has done to the tunnels\l"
	.string "below us?$"

PewterMineNorthHouse_Morgan_Text_6:
	.string "And if you have time, come to the lab\n"
	.string "and tell Oak what you saw. He'll be\l"
	.string "interested in hearing what happened\l"
	.string "from you, too.\l"
	.string "After all, I spent the whole time in\l"
	.string "here...$"
