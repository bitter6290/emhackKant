PewterMine_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterMine_OnTransition
	.byte 0


PewterMine_OnTransition::
	compare VAR_STORY_PROGRESS, 15
	goto_if_gt PewterMine_OnTransition_2
PewterMine_OnTransition_1:
	end

PewterMine_OnTransition_2:
	removeobject 1
	removeobject 2
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
	goto PewterMine_JoinCaleb_1


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
