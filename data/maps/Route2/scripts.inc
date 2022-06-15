Route2_MapScripts::
	.byte 0


Route2_Grunt::
	lock
	compare VAR_STORY_PROGRESS, 15
	goto_if_lt Route2_Grunt_2
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
Route2_Stop_1:
	release
	end

Route2_Stop_2:
	playse SE_PIN
	getplayerxy VAR_RESULT, VAR_TEMP_1
	compare VAR_TEMP_1, 50
	goto_if_gt Route2_Stop_5
	compare VAR_RESULT, 12
	goto_if_gt Route2_Stop_11
	applymovement 1, ExclamLeft
Route2_Stop_4:
	waitmovement 0
	msgbox Route2_Stop_Text_0
	msgbox Route2_GruntMessage1
	goto Route2_AmbiRetreat
	goto Route2_Stop_1

Route2_Stop_5:
	compare VAR_RESULT, 14
	goto_if_gt Route2_Stop_8
	applymovement 2, ExclamLeft
	goto Route2_Stop_4

Route2_Stop_8:
	applymovement 2, ExclamRight
	goto Route2_Stop_4

Route2_Stop_11:
	applymovement 1, ExclamRight
	goto Route2_Stop_4


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

Route2_Stop_Text_0:
	.string "Hey!$"

Route2_HikerMessage_Text_0:
	.string "Go through here if you really want. I\n"
	.string "won't stop you.$"

Route2_GruntMessageToll::
	.string "Hey! If you wanna go through, you have\n"
	.string "to pay the fee! It'll be 100$ to get\l"
	.string "through!$"

Route2_GruntMessage1::
	.string "We're gonna be setting up a tollbooth\n"
	.string "here!\l"
	.string "It's not ready yet, so you'll have to\l"
	.string "find another way.$"
