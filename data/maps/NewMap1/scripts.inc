NewMap1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewMap1_OnResume
	.byte 0


NewMap1_OnResume::
	setrespawn HEAL_LOCATION_PALLET_TOWN
	removeobject 1
	setflag FLAG_TEMP_5
	end


NewMap1_OakStopsPlayer::
	lock
	compare VAR_STORY_PROGRESS, 2
	goto_if_lt NewMap1_OakStopsPlayer_2
	compare VAR_STORY_PROGRESS, 2
	goto_if_eq NewMap1_OakStopsPlayer_3
NewMap1_OakStopsPlayer_1:
	release
	end

NewMap1_OakStopsPlayer_2:
	msgbox NewMap1_OakStopsPlayer_Text_0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, DownExclam
	waitmovement OBJ_EVENT_ID_PLAYER
	getplayerxy VAR_RESULT, VAR_TEMP_1
	clearflag FLAG_TEMP_5
	addobject 1
	compare VAR_RESULT, 11
	goto_if_eq NewMap1_OakStopsPlayer_7
NewMap1_OakStopsPlayer_6:
	applymovement 1, Pallet_OakUp
	waitmovement 1
	compare VAR_STORY_PROGRESS, 0
	goto_if_eq NewMap1_OakStopsPlayer_13
	msgbox NewMap1_OakStopsPlayer_Text_2
NewMap1_OakStopsPlayer_12:
	applymovement 1, Pallet_OakDown
	waitmovement 1
	removeobject 1
	applymovement OBJ_EVENT_ID_PLAYER, Pallet_PlayerRetreat
	waitmovement OBJ_EVENT_ID_PLAYER
	goto NewMap1_OakStopsPlayer_1

NewMap1_OakStopsPlayer_3:
	msgbox NewMap1_OakStopsPlayer_Text_0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, DownExclam
	waitmovement OBJ_EVENT_ID_PLAYER
	getplayerxy VAR_RESULT, VAR_TEMP_1
	clearflag FLAG_TEMP_5
	addobject 1
	compare VAR_RESULT, 11
	goto_if_eq NewMap1_OakStopsPlayer_10
NewMap1_OakStopsPlayer_9:
	applymovement 1, Pallet_OakUp
	waitmovement 1
	msgbox NewMap1_OakStopsPlayer_Text_3
	msgbox NewMap1_OakStopsPlayer_Text_4
	applymovement 1, Pallet_OakDown
	waitmovement 1
	removeobject 1
	addvar VAR_STORY_PROGRESS, 1
	goto NewMap1_OakStopsPlayer_1

NewMap1_OakStopsPlayer_7:
	applymovement 1, Pallet_OakStepLeft
	waitmovement 1
	goto NewMap1_OakStopsPlayer_6

NewMap1_OakStopsPlayer_10:
	applymovement 1, Pallet_OakStepLeft
	waitmovement 1
	goto NewMap1_OakStopsPlayer_9

NewMap1_OakStopsPlayer_13:
	msgbox NewMap1_OakStopsPlayer_Text_1
	goto NewMap1_OakStopsPlayer_12


DownExclam::
	face_down
	emote_exclamation_mark
	step_end

Pallet_PlayerRetreat:
	walk_down
	step_end

Pallet_OakStepLeft:
	walk_left
	step_end

Pallet_OakUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Pallet_OakDown:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewMap1_OakStopsPlayer_Text_0:
	.string "Oak: {PLAYER}!$"

NewMap1_OakStopsPlayer_Text_1:
	.string "Oak: You can't go out without a\n"
	.string "Pokémon!\l"
	.string "If you want to talk about leaving\l"
	.string "Pallet Town, come to my lab.$"

NewMap1_OakStopsPlayer_Text_2:
	.string "Oak: It's too dangerous to go out\n"
	.string "without a Pokémon!\l"
	.string "Take one from my lab before you go out!$"

NewMap1_OakStopsPlayer_Text_3:
	.string "Since you're leaving town... I would like\n"
	.string "to ask you one small favor.\l"
	.string "Morgan, one of my assistants, left a day\l"
	.string "ago to study Pokémon at the mine in\l"
	.string "Pewter City.\l"
	.string "She told me she would be back by today,\l"
	.string "and I can't help but worry.\l"
	.string "Could you go and check on her? Pewter\l"
	.string "City is just two towns to the north of\l"
	.string "here, and the roads in between ought\l"
	.string "to be easy to navigate.$"

NewMap1_OakStopsPlayer_Text_4:
	.string "Thank you, {PLAYER}.$"
