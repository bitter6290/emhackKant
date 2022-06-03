PewterMine_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterMine_OnTransition
	.byte 0


PewterMine_OnTransition::
	compare VAR_STORY_PROGRESS, 14
	goto_if_lt PewterMine_OnTransition_2
PewterMine_OnTransition_1:
	end

PewterMine_OnTransition_2:
	setflag FLAG_TEMP_3
	goto PewterMine_OnTransition_1


PewterMine_JoinEmilie::
	lock
	compare VAR_STORY_PROGRESS, 14
	goto_if_lt PewterMine_JoinEmilie_2
PewterMine_JoinEmilie_1:
	release
	end

PewterMine_JoinEmilie_2:
	msgbox PewterMine_JoinEmilie_Text_0
	faceplayer
	msgbox PewterMine_JoinEmilie_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PewterMine_JoinEmilie_4
	goto PewterMine_JoinEmilie_1

PewterMine_JoinEmilie_4:
	multi_fixed_2_vs_1 TRAINER_GRUNT_AQUA_HIDEOUT_2, PewterMine_JoinEmilie_Text_2, TRAINER_GRUNT_AQUA_HIDEOUT_1, 3
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq PewterMine_JoinEmilie_6
	special SetCB2WhiteOut
	goto PewterMine_JoinEmilie_1

PewterMine_JoinEmilie_6:
	setvar VAR_STORY_PROGRESS, 14
	playbgm MUS_RG_ROCKET_HIDEOUT, FALSE
	delay 10
	goto PewterMine_Explosion
	goto PewterMine_JoinEmilie_1


PewterMine_JoinCaleb::
	lock
	compare VAR_STORY_PROGRESS, 14
	goto_if_lt PewterMine_JoinCaleb_2
PewterMine_JoinCaleb_1:
	release
	end

PewterMine_JoinCaleb_2:
	msgbox PewterMine_JoinCaleb_Text_0
	faceplayer
	msgbox PewterMine_JoinCaleb_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PewterMine_JoinCaleb_4
	goto PewterMine_JoinCaleb_1

PewterMine_JoinCaleb_4:
	multi_fixed_2_vs_1 TRAINER_GRUNT_AQUA_HIDEOUT_3, PewterMine_JoinCaleb_Text_2, TRAINER_SAWYER_1, 2
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq PewterMine_JoinCaleb_6
	special SetCB2WhiteOut
	goto PewterMine_JoinCaleb_1

PewterMine_JoinCaleb_6:
	setvar VAR_STORY_PROGRESS, 14
	playbgm MUS_RG_ROCKET_HIDEOUT, FALSE
	delay 10
	goto PewterMine_Explosion
	goto PewterMine_JoinCaleb_1


PewterMine_FirstEntrance::
	lock
	compare VAR_STORY_PROGRESS, 5
	goto_if_lt PewterMine_FirstEntrance_2
	compare VAR_STORY_PROGRESS, 14
	goto_if_lt PewterMine_FirstEntrance_3
PewterMine_FirstEntrance_1:
	release
	end

PewterMine_FirstEntrance_2:
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, PewterMine_Exclam
	playbgm MUS_RG_ROCKET_HIDEOUT, FALSE
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, PewterMine_CameraFirst
	waitmovement 0
	applymovement 6, PewterMine_FirstGrunt2
	msgbox PewterMine_FirstEntrance_Text_0
	applymovement 7, PewterMine_FirstGrunt
	msgbox PewterMine_FirstEntrance_Text_1
	applymovement OBJ_EVENT_ID_CAMERA, PewterMine_CameraFirstBack
	waitmovement 0
	special RemoveCameraObject
	addvar VAR_STORY_PROGRESS, 1
	goto PewterMine_FirstEntrance_1

PewterMine_FirstEntrance_3:
	playbgm MUS_RG_ROCKET_HIDEOUT, FALSE
	goto PewterMine_FirstEntrance_1


PewterMine_Magma6Dia::
	lock
	msgbox PewterMine_Magma6Dia_Text_0
	release
	end


PewterMine_Aqua7Dia::
	lock
	msgbox PewterMine_Aqua7Dia_Text_0
	release
	end


PewterMine_Magma9Dia::
	return


PewterMine_Magma10Dia::
	lock
	msgbox PewterMine_Magma10Dia_Text_0
	faceplayer
	playse SE_PIN
	applymovement 10, PewterMine_Exclam
	waitmovement 10
	msgbox PewterMine_Magma10Dia_Text_1
	release
	end


PewterMine_Explosion::
	lock
	delay 5
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, PewterMine_CameraExplosion
	waitmovement 0
	playse SE_PIN
	applymovement 8, PewterMine_Aqua8Jump
	waitmovement 8
	msgbox PewterMine_Explosion_Text_0
	playse SE_PIN
	applymovement 4, PewterMine_Exclam
	waitmovement 4
	msgbox PewterMine_Explosion_Text_1
	msgbox PewterMine_Explosion_Text_2
	waitmessage
	applymovement 8, PewterMine_Aqua8Run
	applymovement 4, PewterMine_SorenRun
	applymovement 6, PewterMine_Aqua7Run
	applymovement 7, PewterMine_Aqua7Run
	applymovement 9, PewterMine_Magma9Run
	applymovement 3, PewterMine_Aqua3Run
	applymovement 5, PewterMine_Aqua3Run
	waitmovement 0
	fadescreen 1
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	removeobject 9
	removeobject 10
	removeobject 11
	special ShakeCamera
	setflag FLAG_PEWTER_MINE_DONE
	applymovement OBJ_EVENT_ID_CAMERA, PewterMine_CameraBack
	waitmovement 0
	special RemoveCameraObject
	clearflag FLAG_TEMP_3
	showobjectat 13, MAP_PEWTER_MINE
	showobjectat 14, MAP_PEWTER_MINE
	showobjectat 15, MAP_PEWTER_MINE
	showobjectat 16, MAP_PEWTER_MINE
	fadescreen 0
	playbgm MUS_RG_PEWTER, FALSE
	release
	end


PewterMine_Aqua7Run:
	walk_diag_northeast
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

PewterMine_Magma9Run:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

PewterMine_Aqua3Run:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_diag_northeast
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

PewterMine_Aqua8Run:
	walk_fast_right
	walk_fast_right
	walk_diag_northeast
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_diag_northeast
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

PewterMine_Aqua8Jump:
	emote_exclamation_mark
	delay_16
	jump_in_place_right
	jump_in_place_right
	step_end

PewterMine_SorenRun:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_diag_northeast
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_diag_northeast
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

PewterMine_Aqua11Run:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_diag_northeast
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_diag_northeast
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

PewterMine_Exclam::
	emote_exclamation_mark
	step_end

PewterMine_CameraExplosion:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

PewterMine_CameraBack:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PewterMine_CameraFirst:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	step_end

PewterMine_CameraFirstBack:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

PewterMine_FirstGrunt:
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end

PewterMine_FirstGrunt2:
	walk_in_place_up
	walk_in_place_up
	walk_in_place_up
	step_end

PewterMine_JoinEmilie_Text_0:
	.string "Ugh... I'll show you! You grunts have\n"
	.string "nothing on us!$"

PewterMine_JoinEmilie_Text_1:
	.string "Hey, you! Help me beat this guy!$"

PewterMine_JoinEmilie_Text_2:
	.string "How...$"

PewterMine_JoinCaleb_Text_0:
	.string "You people have no right to be here!\n"
	.string "Here, or anywhere in Kanto!$"

PewterMine_JoinCaleb_Text_1:
	.string "Hey! Help me chase this grunt away!$"

PewterMine_JoinCaleb_Text_2:
	.string "No!$"

PewterMine_FirstEntrance_Text_0:
	.string "Come on! It's already over for you!$"

PewterMine_FirstEntrance_Text_1:
	.string "Shut up! We've already cleared you out\n"
	.string "of the mine!\l"
	.string "Anyone can see that you're losing!$"

PewterMine_Magma6Dia_Text_0:
	.string "Zubat! Confuse the enemy!$"

PewterMine_Aqua7Dia_Text_0:
	.string "Ack... What are you people doing on our\n"
	.string "turf?$"

PewterMine_Magma10Dia_Text_0:
	.string "Heh... Our plan is already in place! Those\n"
	.string "fools just don't know it yet...$"

PewterMine_Magma10Dia_Text_1:
	.string "Who are you?\n"
	.string "You didn't hear anything, OK?$"

PewterMine_Explosion_Text_0:
	.string "It's a bomb!$"

PewterMine_Explosion_Text_1:
	.string "Hold da kaeft!$"

PewterMine_Explosion_Text_2:
	.string "Run!$"
