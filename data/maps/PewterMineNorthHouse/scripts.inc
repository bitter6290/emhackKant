PewterMineNorthHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PewterMineNorthHouse_OnLoad
	.byte 0


PewterMineNorthHouse_OnLoad::
	compare VAR_STORY_PROGRESS, 14
	goto_if_gt PewterMineNorthHouse_OnLoad_2
PewterMineNorthHouse_OnLoad_1:
	end

PewterMineNorthHouse_OnLoad_2:
	setflag FLAG_TEMP_3
	goto PewterMineNorthHouse_OnLoad_1


PewterMineNorthHouse_Morgan::
	lock
	compare VAR_STORY_PROGRESS, 14
	goto_if_eq PewterMineNorthHouse_Morgan_2
PewterMineNorthHouse_Morgan_1:
	release
	end

PewterMineNorthHouse_Morgan_2:
	getplayerxy VAR_RESULT, VAR_TEMP_1
	playse SE_PIN
	applymovement 1, PewterMine_Exclam
	waitmovement 1
	msgbox PewterMineNorthHouse_Morgan_Text_0
	compare VAR_RESULT, 7
	goto_if_eq PewterMineNorthHouse_Morgan_5
PewterMineNorthHouse_Morgan_4:
	applymovement 1, PewterMineNorthHouse_MorganSouth
	waitmovement 1
	applymovement 1, PewterMineNorthHouse_MorganSouth
	waitmovement 1
	msgbox PewterMineNorthHouse_Morgan_Text_1
	applymovement 1, PewterMineNorthHouse_MorganSide
	waitmovement 1
	msgbox PewterMineNorthHouse_Morgan_Text_2
	msgbox PewterMineNorthHouse_Morgan_Text_3
	waitmessage
	delay 30
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
	waitmovement 1
	playse SE_DOOR
	setflag FLAG_TEMP_3
	removeobject 1
	addvar VAR_STORY_PROGRESS, 1
	goto PewterMineNorthHouse_Morgan_1

PewterMineNorthHouse_Morgan_5:
	applymovement OBJ_EVENT_ID_PLAYER, PewterMineNorth_PlayerStep
	goto PewterMineNorthHouse_Morgan_4


PewterMineNorthHouse_MorganSouth:
	walk_down
	step_end

PewterMineNorthHouse_MorganSide:
	face_left
	delay_16
	face_down
	step_end

PewterMineNorthHouse_MorganThree:
	walk_left
	walk_down
	walk_down
	face_right
	step_end

PewterMineNorth_PlayerStep:
	walk_right
	face_up
	step_end

PewterMineNorthHouse_Morgan_Text_0:
	.string "Ah!$"

PewterMineNorthHouse_Morgan_Text_1:
	.string "Are you... {PLAYER}?\n"
	.string "So Oak must have sent you.$"

PewterMineNorthHouse_Morgan_Text_2:
	.string "I'm Morgan, his assistant.\n"
	.string "As you might have guessed, I got\l"
	.string "trapped in here when the fighting\l"
	.string "started.$"

PewterMineNorthHouse_Morgan_Text_3:
	.string "Incidentally, that sound just now...$"

PewterMineNorthHouse_Morgan_Text_4:
	.string "An explosion? Really!?$"

PewterMineNorthHouse_Morgan_Text_5:
	.string "I need to get out of here. And you\n"
	.string "should too, {PLAYER}. We don't know\l"
	.string "how badly the mine tunnels were\l"
	.string "damaged...$"

PewterMineNorthHouse_Morgan_Text_6:
	.string "Oh! And if you have time, come back to\n"
	.string "the lab and tell Oak what you saw. He'll\l"
	.string "be interested in hearing the story\l"
	.string "from you, too.\l"
	.string "After all, I spent the whole time in\l"
	.string "here...$"
