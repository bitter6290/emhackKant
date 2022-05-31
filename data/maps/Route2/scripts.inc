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
	compare VAR_RESULT, 14
	goto_if_gt Route2_Stop_5
	compare VAR_TEMP_1, 50
	goto_if_gt Route2_Stop_15
	applymovement 1, ExclamLeft
Route2_Stop_4:
	waitmovement 0
	msgbox Route2_Stop_Text_0
	msgbox Route2_GruntMessage1
	compare VAR_TEMP_1, 50
	goto_if_gt Route2_Stop_9
	applymovement OBJ_EVENT_ID_PLAYER, Route2_RetreatUp
Route2_Stop_8:
	waitmovement OBJ_EVENT_ID_PLAYER
	goto Route2_Stop_1

Route2_Stop_5:
	compare VAR_TEMP_1, 50
	goto_if_gt Route2_Stop_12
	applymovement 1, ExclamRight
	goto Route2_Stop_4

Route2_Stop_9:
	applymovement OBJ_EVENT_ID_PLAYER, Route2_PlayerRetreats
	goto Route2_Stop_8

Route2_Stop_12:
	applymovement 2, ExclamRight
	goto Route2_Stop_4

Route2_Stop_15:
	applymovement 2, ExclamLeft
	goto Route2_Stop_4


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

Route2_GruntMessage1::
	.string "We're gonna be setting up a tollbooth\n"
	.string "here!\l"
	.string "It's not ready yet, so you'll have to\l"
	.string "find another way.$"
