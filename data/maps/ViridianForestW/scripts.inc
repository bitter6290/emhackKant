ViridianForestW_MapScripts::
	.byte 0


VFW_HikerFirst::
	lock
	compare VAR_STORY_PROGRESS, 4
	goto_if_lt VFW_HikerFirst_2
VFW_HikerFirst_1:
	release
	end

VFW_HikerFirst_2:
	msgbox VFW_HikerFirst_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, VFW_ExclamLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox VFW_HikerFirst_Text_1
	setvar VAR_STORY_PROGRESS, 4
	goto VFW_HikerFirst_1


VFW_ExclamLeft:
	face_left
	emote_exclamation_mark
	step_end

VFW_HikerFirst_Text_0:
	.string "Hey! You!$"

VFW_HikerFirst_Text_1:
	.string "What are you doing going through these\n"
	.string "woods? Nobody comes here anymore, not\l"
	.string "since Archie built that road there.\l"
	.string "If you really want to come through,\l"
	.string "remember this. The plants here have a\l"
	.string "pattern to them, one that should help\l"
	.string "you to keep your bearings and avoid\l"
	.string "running in circles.\l"
	.string "Your party should be prepared, too. I've\l"
	.string "heard that a new Fire-type Pokémon\l"
	.string "was spotted in the fields southeast of\l"
	.string "here, and it'll keep the bugs away from\l"
	.string "you for sure!$"
