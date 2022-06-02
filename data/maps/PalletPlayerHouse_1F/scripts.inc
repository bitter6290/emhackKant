PalletPlayerHouse_1F_MapScripts::
	.byte 0


TalkToMom::
	lock
	compare VAR_STORY_PROGRESS, 2
	goto_if_lt TalkToMom_2
	msgbox TalkToMom_Text_2
	special HealPlayerParty
	msgbox TalkToMom_Text_3
	msgbox TalkToMom_Text_4
TalkToMom_1:
	release
	end

TalkToMom_2:
	msgbox TalkToMom_Text_0
	msgbox TalkToMom_Text_1
	goto TalkToMom_1


TalkToMom_Text_0:
	.string "Oh, {PLAYER}!$"

TalkToMom_Text_1:
	.string "I heard from Professor Oak that you\n"
	.string "were thinking about leaving Pallet\l"
	.string "Town.\l"
	.string "It's important for a boy like you to see\l"
	.string "the world, but please stay safe. And\l"
	.string "come back home to me once in a while!$"

TalkToMom_Text_2:
	.string "{PLAYER}! You're home! Why don't you\n"
	.string "take a little rest and heal up your\l"
	.string "Pokémon?$"

TalkToMom_Text_3:
	.string "All better!$"

TalkToMom_Text_4:
	.string "Come back to see me soon! I'm so proud\n"
	.string "to see you become a Trainer.$"
