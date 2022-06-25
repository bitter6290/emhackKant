Route2_MapScripts::
	.byte 0


Route2_Grunt::
	lock
	compare VAR_STORY_PROGRESS, 15
	goto_if_lt Route2_Grunt_2
	msgbox Route2_Grunt_Text_1
Route2_Grunt_1:
	release
	end

Route2_Grunt_2:
	msgbox Route2_Grunt_Text_0
	goto Route2_Grunt_1


Route2_Stop::
	lock
	compare VAR_STORY_PROGRESS, 15
	goto_if_lt Route2_Stop_2
	playse SE_PIN
	getplayerxy VAR_RESULT, VAR_TEMP_1
	compare VAR_TEMP_1, 50
	goto_if_gt Route2_Stop_10
	compare VAR_RESULT, 12
	goto_if_gt Route2_Stop_25
	applymovement 1, ExclamLeft
Route2_Stop_9:
	msgbox Route2_Stop_Text_0
	msgbox Route2_GruntMessageToll
	msgbox Route2_Stop_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route2_Stop_19
	msgbox Route2_Stop_Text_3
	goto Route2_AmbiRetreat
Route2_Stop_1:
	release
	end

Route2_Stop_2:
	playse SE_PIN
	getplayerxy VAR_RESULT, VAR_TEMP_1
	compare VAR_TEMP_1, 50
	goto_if_gt Route2_Stop_6
	compare VAR_RESULT, 12
	goto_if_gt Route2_Stop_16
	applymovement 1, ExclamLeft
Route2_Stop_5:
	waitmovement 0
	msgbox Route2_Stop_Text_0
	msgbox Route2_GruntMessage1
	goto Route2_AmbiRetreat
	goto Route2_Stop_1

Route2_Stop_6:
	compare VAR_RESULT, 14
	goto_if_gt Route2_Stop_13
	applymovement 2, ExclamLeft
	goto Route2_Stop_5

Route2_Stop_10:
	compare VAR_RESULT, 14
	goto_if_gt Route2_Stop_22
	applymovement 2, ExclamLeft
	goto Route2_Stop_9

Route2_Stop_13:
	applymovement 2, ExclamRight
	goto Route2_Stop_5

Route2_Stop_16:
	applymovement 1, ExclamRight
	goto Route2_Stop_5

Route2_Stop_19:
	checkmoney 50
	compare VAR_RESULT, 1
	goto_if_eq Route2_Stop_28
	goto Route2_Stop_1

Route2_Stop_22:
	applymovement 2, ExclamRight
	goto Route2_Stop_9

Route2_Stop_25:
	applymovement 1, ExclamRight
	goto Route2_Stop_9

Route2_Stop_28:
	removemoney 50
	msgbox Route2_Stop_Text_2
	goto Route2_AmbiForward
	goto Route2_Stop_1


Route2_AmbiRetreat::
	compare VAR_TEMP_1, 50
	goto_if_gt Route2_AmbiRetreat_2
	applymovement OBJ_EVENT_ID_PLAYER, Route2_RetreatUp
Route2_AmbiRetreat_1:
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

Route2_AmbiRetreat_2:
	applymovement OBJ_EVENT_ID_PLAYER, Route2_PlayerRetreats
	goto Route2_AmbiRetreat_1


Route2_AmbiForward::
	compare VAR_TEMP_1, 50
	goto_if_gt Route2_AmbiForward_2
	applymovement OBJ_EVENT_ID_PLAYER, Route2_PlayerRetreats
Route2_AmbiForward_1:
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

Route2_AmbiForward_2:
	applymovement OBJ_EVENT_ID_PLAYER, Route2_RetreatUp
	goto Route2_AmbiForward_1


Route2_HikerMessage::
	lock
	msgbox Route2_HikerMessage_Text_0
	release
	end


ExclamRight:
	face_right
	emote_exclamation_mark
	step_end

ExclamLeft:
	face_left
	emote_exclamation_mark
	step_end

FaceDown::
	face_down
	step_end

Route2_PlayerRetreats:
	walk_down
	step_end

Route2_RetreatUp:
	walk_up
	step_end

Route2_Grunt_Text_0:
	.string "We're gonna be setting up a tollbooth\n"
	.string "here!\l"
	.string "It's not ready yet, so you'll have to\l"
	.string "find another way.$"

Route2_Grunt_Text_1:
	.string "What are you talking to me for? I'm busy\n"
	.string "running this tollbooth!$"

Route2_Stop_Text_0:
	.string "Hey!$"

Route2_Stop_Text_1:
	.string "Pay the grunt?$"

Route2_Stop_Text_2:
	.string "Go ahead, then.$"

Route2_Stop_Text_3:
	.string "You're not paying? Get lost, then!$"

Route2_HikerMessage_Text_0:
	.string "Go through here if you really want. I\n"
	.string "won't stop you.$"

Route2_GruntMessageToll::
	.string "If you wanna go through, you have to\n"
	.string "pay the fee!\l"
	.string "That'll be 50!$"

Route2_GruntMessage1::
	.string "We're gonna be setting up a tollbooth\n"
	.string "here!\l"
	.string "It's not ready yet, so you'll have to\l"
	.string "find another way.$"
