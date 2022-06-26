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
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, VFW_ExclamLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox VFW_HikerFirst_Text_1
	setvar VAR_STORY_PROGRESS, 4
	goto VFW_HikerFirst_1


VFW_EventScript_BTim::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, VFW_EventScript_BTim_Text_0, VFW_EventScript_BTim_Text_1
	msgbox VFW_EventScript_BTim_Text_2, MSGBOX_AUTOCLOSE
	end


VFW_GrottoMasterSign::
	lock
	msgbox VFW_GrottoMasterSign_Text_0
	release
	end


VFW_EventScript_Charlotte::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, VFW_EventScript_Charlotte_Text_0, VFW_EventScript_Charlotte_Text_1
	msgbox VFW_EventScript_Charlotte_Text_2, MSGBOX_AUTOCLOSE
	end


VFW_ExclamLeft:
	face_left
	emote_exclamation_mark
	step_end

VFW_HikerFirst_Text_0:
	.string "Hey! You!$"

VFW_HikerFirst_Text_1:
	.string "What are you doing going through these\n"
	.string "woods? Nobody comes here anymore, not\l"
	.string "since the boss built that road there.\l"
	.string "If you really want to come through,\l"
	.string "remember this. There's a pattern to the\l"
	.string "plants here, one that should help you\l"
	.string "to keep your bearings and avoid\l"
	.string "running in circles.\l"
	.string "Your party should be prepared, too. I've\l"
	.string "heard that a new Fire-type Pokémon\l"
	.string "was spotted in the fields southeast of\l"
	.string "here, and it'll keep the bugs away from\l"
	.string "you for sure!$"

VFW_EventScript_BTim_Text_0:
	.string "I'll show you the rare Pokémon I found\n"
	.string "last week!$"

VFW_EventScript_BTim_Text_1:
	.string "Stumbled into defeat...$"

VFW_EventScript_BTim_Text_2:
	.string "To tell the truth, I was lost in this\n"
	.string "forest when I found my Pikachu.\l"
	.string "But I haven't found another once\l"
	.string "since...$"

VFW_GrottoMasterSign_Text_0:
	.string "Even if there's only one way through an\n"
	.string "area, it never hurts to explore all the\l"
	.string "possible routes!\l"
	.string "You never know what you might come\l"
	.string "across!$"

VFW_EventScript_Charlotte_Text_0:
	.string "Hey!\n"
	.string "Don't disturb the plants!$"

VFW_EventScript_Charlotte_Text_1:
	.string "Ah, stepped on a flower...$"

VFW_EventScript_Charlotte_Text_2:
	.string "Are you trying to get to Pewter City?\l"
	.string "You're about halfway there now, I think.$"
