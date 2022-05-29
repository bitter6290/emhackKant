Route2_MapScripts::
	.byte 0


Route2_SouthGrunt::
	lock
	compare VAR_STORY_PROGRESS, 15
	goto_if_lt Route2_SouthGrunt_2
Route2_SouthGrunt_1:
	release
	end

Route2_SouthGrunt_2:
	msgbox Route2_SouthGrunt_Text_0
	goto Route2_SouthGrunt_1


Route2_SouthStop::
	lock
	compare VAR_STORY_PROGRESS, 15
	goto_if_lt Route2_SouthStop_2
Route2_SouthStop_1:
	release
	end

Route2_SouthStop_2:
	playse SE_PIN
	getplayerxy VAR_RESULT, VAR_TEMP_1
	compare VAR_RESULT, 14
	goto_if_gt Route2_SouthStop_5
	applymovement 2, ExclamLeft
Route2_SouthStop_4:
	waitmovement 2
	msgbox Route2_SouthStop_Text_0
	msgbox Route2_GruntMessage1
	applymovement OBJ_EVENT_ID_PLAYER, Route2_PlayerRetreats
	waitmovement OBJ_EVENT_ID_PLAYER
	goto Route2_SouthStop_1

Route2_SouthStop_5:
	applymovement 2, ExclamRight
	goto Route2_SouthStop_4


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

Route2_SouthGrunt_Text_0:
	.string "We're gonna be setting up a tollbooth\n"
	.string "here!\l"
	.string "It's not ready yet, so you'll have to\l"
	.string "find another way.$"

Route2_SouthStop_Text_0:
	.string "Hey!$"

Route2_HikerMessage_Text_0:
	.string "Go through here if you really want. I\n"
	.string "won't stop you.$"

Route2_GruntMessage1::
	.string "We're gonna be setting up a tollbooth\n"
	.string "here!\l"
	.string "It's not ready yet, so you'll have to\l"
	.string "find another way.$"
