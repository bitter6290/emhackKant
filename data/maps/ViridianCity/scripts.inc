ViridianCity_MapScripts::
	.byte 0


ViridianGymSign::
	lock
	msgbox ViridianGymSign_Text_0
	release
	end


Viridian_BerrySeller::
	lock
	msgbox Viridian_BerrySeller_Text_0
	msgbox Viridian_BerrySeller_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Viridian_BerrySeller_2
Viridian_BerrySeller_1:
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

Viridian_BerrySeller_2:
	pokemart Viridian_Berries
	goto Viridian_BerrySeller_1


Viridian_GymBlocker::
	lock
	compare VAR_STORY_PROGRESS, 14
	goto_if_lt Viridian_GymBlocker_2
	msgbox Viridian_GymBlocker_Text_1
Viridian_GymBlocker_1:
	release
	end

Viridian_GymBlocker_2:
	msgbox Viridian_GymBlocker_Text_0
	goto Viridian_GymBlocker_1


	.align 2
Viridian_Berries:
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_NONE

ViridianGymSign_Text_0:
	.string "Viridian City Gym\l"
	.string "Leader: Soren\l"
	.string "Kanto's top speleologist!$"

Viridian_BerrySeller_Text_0:
	.string "Hi! I'm Viridian City's Berry Trader!$"

Viridian_BerrySeller_Text_1:
	.string "Would you like to buy some of my\n"
	.string "berries?$"

Viridian_GymBlocker_Text_0:
	.string "Soren left a few days ago to conduct\n"
	.string "inspections at the Pewter Mine.\l"
	.string "Sadly, I can't let you in the gym right\l"
	.string "now!$"

Viridian_GymBlocker_Text_1:
	.string "Soren is overseeing the repair efforts\n"
	.string "at Pewter Mine right now.\l"
	.string "He'll be happy to take challengers when\l"
	.string "he's done!$"
