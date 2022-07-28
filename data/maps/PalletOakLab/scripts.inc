PalletOakLab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, OakLab_OnLoad
	.byte 0


OakLab_OnLoad::
	compare VAR_STORY_PROGRESS, 15
	goto_if_lt OakLab_OnLoad_2
OakLab_OnLoad_1:
	end

OakLab_OnLoad_2:
	setflag FLAG_TEMP_3
	goto OakLab_OnLoad_1


PalletOakLab_OakDialogue::
	lock
	faceplayer
	compare VAR_STORY_PROGRESS, 0
	goto_if_eq PalletOakLab_OakDialogue_2
	compare VAR_STORY_PROGRESS, 15
	goto_if_lt PalletOakLab_OakDialogue_3
	compare VAR_STORY_PROGRESS, 15
	goto_if_eq PalletOakLab_OakDialogue_4
PalletOakLab_OakDialogue_1:
	release
	end

PalletOakLab_OakDialogue_2:
	msgbox PalletOakLab_OakDialogue_Text_0
	msgbox PalletOakLab_OakDialogue_Text_1
	waitmessage
	playse SE_PIN
	applymovement 4, Exclam
	waitmovement 4
	msgbox PalletOakLab_OakDialogue_Text_2
	msgbox PalletOakLab_OakDialogue_Text_3
	playfanfare MUS_OBTAIN_ITEM
	message PalletOakLab_OakDialogue_Text_4
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_STORY_PROGRESS, 1
	msgbox PalletOakLab_OakDialogue_Text_5
	setflag FLAG_SYS_B_DASH
	playfanfare MUS_OBTAIN_ITEM
	message PalletOakLab_OakDialogue_Text_6
	waitfanfare
	giveitem ITEM_POKE_BALL, 10
	giveitem ITEM_POTION, 5
	giveitem ITEM_TM_CASE, 1
	goto PalletOakLab_OakDialogue_1

PalletOakLab_OakDialogue_3:
	msgbox PalletOakLab_OakDialogue_Text_7
	goto PalletOakLab_OakDialogue_1

PalletOakLab_OakDialogue_4:
	msgbox PalletOakLab_OakDialogue_Text_8
	msgbox PalletOakLab_OakDialogue_Text_9
	delay 45
	playse SE_PIN
	applymovement 4, Exclam
	waitmovement 4
	msgbox PalletOakLab_OakDialogue_Text_10
	delay 15
	msgbox PalletOakLab_OakDialogue_Text_11
	applymovement 4, OakLabTurns
	waitmovement 4
	msgbox PalletOakLab_OakDialogue_Text_12
	msgbox PalletOakLab_OakDialogue_Text_13
	msgbox PalletOakLab_OakDialogue_Text_14
	addvar VAR_STORY_PROGRESS, 1
	goto PalletOakLab_OakDialogue_1


PalletOakLab_ChooseBulbasaur::
	lock
	compare VAR_STORY_PROGRESS, 0
	goto_if_eq PalletOakLab_ChooseBulbasaur_2
	compare VAR_STORY_PROGRESS, 1
	goto_if_eq PalletOakLab_ChooseBulbasaur_3
	msgbox PalletOakLab_ChooseBulbasaur_Text_5
PalletOakLab_ChooseBulbasaur_1:
	release
	end

PalletOakLab_ChooseBulbasaur_2:
	msgbox PalletOakLab_ChooseBulbasaur_Text_0
	goto PalletOakLab_ChooseBulbasaur_1

PalletOakLab_ChooseBulbasaur_3:
	msgbox PalletOakLab_ChooseBulbasaur_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PalletOakLab_ChooseBulbasaur_7
	goto PalletOakLab_ChooseBulbasaur_1

PalletOakLab_ChooseBulbasaur_7:
	getpartysize
	compare VAR_RESULT, 6
	goto_if_lt PalletOakLab_ChooseBulbasaur_9
	msgbox PalletOakLab_ChooseBulbasaur_Text_4
	goto PalletOakLab_ChooseBulbasaur_1

PalletOakLab_ChooseBulbasaur_9:
	givemon SPECIES_BULBASAUR, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_TOOK_BULBASAUR
	addvar VAR_STORY_PROGRESS, 1
	removeobject 3
	playfanfare MUS_OBTAIN_ITEM
	msgbox PalletOakLab_ChooseBulbasaur_Text_2
	waitfanfare
	msgbox PalletOakLab_ChooseBulbasaur_Text_3, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PalletOakLab_ChooseBulbasaur_12
	goto PalletOakLab_ChooseBulbasaur_1

PalletOakLab_ChooseBulbasaur_12:
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto PalletOakLab_ChooseBulbasaur_1


PalletOakLab_ChooseCharmander::
	lock
	compare VAR_STORY_PROGRESS, 0
	goto_if_eq PalletOakLab_ChooseCharmander_2
	compare VAR_STORY_PROGRESS, 1
	goto_if_eq PalletOakLab_ChooseCharmander_3
	msgbox PalletOakLab_ChooseCharmander_Text_3
PalletOakLab_ChooseCharmander_1:
	release
	end

PalletOakLab_ChooseCharmander_2:
	msgbox PalletOakLab_ChooseBulbasaur_Text_0
	goto PalletOakLab_ChooseCharmander_1

PalletOakLab_ChooseCharmander_3:
	msgbox PalletOakLab_ChooseCharmander_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PalletOakLab_ChooseCharmander_7
	goto PalletOakLab_ChooseCharmander_1

PalletOakLab_ChooseCharmander_7:
	getpartysize
	compare VAR_RESULT, 6
	goto_if_lt PalletOakLab_ChooseCharmander_9
	msgbox PalletOakLab_ChooseBulbasaur_Text_4
	goto PalletOakLab_ChooseCharmander_1

PalletOakLab_ChooseCharmander_9:
	givemon SPECIES_CHARMANDER, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_TOOK_CHARMANDER
	addvar VAR_STORY_PROGRESS, 1
	removeobject 2
	playfanfare MUS_OBTAIN_ITEM
	msgbox PalletOakLab_ChooseCharmander_Text_1
	waitfanfare
	msgbox PalletOakLab_ChooseCharmander_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PalletOakLab_ChooseCharmander_12
	goto PalletOakLab_ChooseCharmander_1

PalletOakLab_ChooseCharmander_12:
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto PalletOakLab_ChooseCharmander_1


PalletOakLab_ChooseSquirtle::
	lock
	compare VAR_STORY_PROGRESS, 0
	goto_if_eq PalletOakLab_ChooseSquirtle_2
	compare VAR_STORY_PROGRESS, 1
	goto_if_eq PalletOakLab_ChooseSquirtle_3
	msgbox PalletOakLab_ChooseSquirtle_Text_3
PalletOakLab_ChooseSquirtle_1:
	release
	end

PalletOakLab_ChooseSquirtle_2:
	msgbox PalletOakLab_ChooseBulbasaur_Text_0
	goto PalletOakLab_ChooseSquirtle_1

PalletOakLab_ChooseSquirtle_3:
	msgbox PalletOakLab_ChooseSquirtle_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PalletOakLab_ChooseSquirtle_7
	goto PalletOakLab_ChooseSquirtle_1

PalletOakLab_ChooseSquirtle_7:
	getpartysize
	compare VAR_RESULT, 6
	goto_if_lt PalletOakLab_ChooseSquirtle_9
	msgbox PalletOakLab_ChooseBulbasaur_Text_4
	goto PalletOakLab_ChooseSquirtle_1

PalletOakLab_ChooseSquirtle_9:
	givemon SPECIES_SQUIRTLE, 5, ITEM_NONE
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_TOOK_SQUIRTLE
	addvar VAR_STORY_PROGRESS, 1
	removeobject 1
	playfanfare MUS_OBTAIN_ITEM
	msgbox PalletOakLab_ChooseSquirtle_Text_1
	waitfanfare
	msgbox PalletOakLab_ChooseSquirtle_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PalletOakLab_ChooseSquirtle_12
	goto PalletOakLab_ChooseSquirtle_1

PalletOakLab_ChooseSquirtle_12:
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto PalletOakLab_ChooseSquirtle_1


PalletOakLab_ScientistTalks::
	lock
	faceplayer
	compare VAR_STORY_PROGRESS, 16
	goto_if_lt PalletOakLab_ScientistTalks_2
PalletOakLab_ScientistTalks_1:
	release
	end

PalletOakLab_ScientistTalks_2:
	msgbox PalletOakLab_ScientistTalks_Text_0
	goto PalletOakLab_ScientistTalks_1


Exclam:
	emote_exclamation_mark
	step_end

OakLabTurns:
	face_left
	delay_16
	face_down
	step_end

PalletOakLab_OakDialogue_Text_0:
	.string "Ah, {PLAYER}!$"

PalletOakLab_OakDialogue_Text_1:
	.string "So you're finally ready to leave. Hmm...\n"
	.string "I know you want to see the world. But\l"
	.string "with everything going on out there, I\l"
	.string "can't stop thinking of what happened\l"
	.string "to him...$"

PalletOakLab_OakDialogue_Text_2:
	.string "Ah, I'm sorry.$"

PalletOakLab_OakDialogue_Text_3:
	.string "{PLAYER}. Kanto is a big place, and\n"
	.string "full of dangers for a young boy like\l"
	.string "you.\l"
	.string "But if you really want to leave, then\l"
	.string "promise me two things.\l"
	.string "First, you will not go alone.\l"
	.string "Take one of the Pokémon on the table\l"
	.string "there with you. It will be your\l"
	.string "protector and your closest companion.\l"
	.string "Second, you will help me in return.\l"
	.string "Over the last five years, hundreds of\l"
	.string "new Pokémon have moved into this\l"
	.string "region, by choice or human\l"
	.string "intervention. With my age and\l"
	.string "reputation, I have no hope of\l"
	.string "documenting them all.\l"
	.string "But you, you could do it. Scour the\l"
	.string "region, study its inhabitants, and\l"
	.string "record it all in this Pokédex!$"

PalletOakLab_OakDialogue_Text_4:
	.string "You obtained the Pokédex!$"

PalletOakLab_OakDialogue_Text_5:
	.string "You'll also need to be equipped for your\n"
	.string "journey. These items will be crucial for\l"
	.string "you as you traverse Kanto. Use them\l"
	.string "well.$"

PalletOakLab_OakDialogue_Text_6:
	.string "You obtained the Running Shoes!$"

PalletOakLab_OakDialogue_Text_7:
	.string "I have nothing more for you right now...\n"
	.string "These last five years have been hard\l"
	.string "even for me.\l"
	.string "But if you fill out the pages of the\l"
	.string "Pokédex, it will benefit you and me\l"
	.string "alike. Your new research could help me\l"
	.string "make marvels again.$"

PalletOakLab_OakDialogue_Text_8:
	.string "Ah, {PLAYER}! What a relief to see\n"
	.string "you! When Morgan told me about the\l"
	.string "explosion, I almost fainted in fear.\l"
	.string "I'm glad to see that you made it out in\l"
	.string "one piece.$"

PalletOakLab_OakDialogue_Text_9:
	.string "You must tell me everything.$"

PalletOakLab_OakDialogue_Text_10:
	.string "Two groups of uniformed grunts were\n"
	.string "fighting over the mine?$"

PalletOakLab_OakDialogue_Text_11:
	.string "So things have gotten that bad...$"

PalletOakLab_OakDialogue_Text_12:
	.string "Listen, {PLAYER}. I'm sure that your\n"
	.string "brief run-in with Team Rocket has\l"
	.string "filled you with confidence. As it\l"
	.string "should, as a newly minted trainer!$"

PalletOakLab_OakDialogue_Text_13:
	.string "But there are more serious things to\n"
	.string "worry about. Do not let yourself be\l"
	.string "convinced that you can handle Team\l"
	.string "Rocket. Hundreds of young trainers\l"
	.string "like you have felt the same, only to\l"
	.string "become ripples in a vast sea of grunts.$"

PalletOakLab_OakDialogue_Text_14:
	.string "I could not bear if the same were to\n"
	.string "happen to you. Keep your wits about\l"
	.string "you, complete your Pokédex, and stay\l"
	.string "well away from the likes of them!$"

PalletOakLab_ChooseBulbasaur_Text_0:
	.string "This ball contains a Pokémon... but it\n"
	.string "belongs to Professor Oak.\l"
	.string "Don't take it without his permission!$"

PalletOakLab_ChooseBulbasaur_Text_1:
	.string "This ball contains Bulbasaur, the\n"
	.string "Grass-type Pokémon!\l"
	.string "Would you like to take it with you?$"

PalletOakLab_ChooseBulbasaur_Text_2:
	.string "You chose Bulbasaur!$"

PalletOakLab_ChooseBulbasaur_Text_3:
	.string "Would you like to give Bulbasaur a\n"
	.string "nickname?$"

PalletOakLab_ChooseBulbasaur_Text_4:
	.string "You shouldn't be able to do this, you\n"
	.string "should probably tell someone.$"

PalletOakLab_ChooseBulbasaur_Text_5:
	.string "This ball contains Bulbasaur, the\n"
	.string "Grass-type Pokémon!$"

PalletOakLab_ChooseCharmander_Text_0:
	.string "This ball contains Charmander, the\n"
	.string "Fire-type Pokémon!\l"
	.string "Would you like to take it with you?$"

PalletOakLab_ChooseCharmander_Text_1:
	.string "You chose Charmander!$"

PalletOakLab_ChooseCharmander_Text_2:
	.string "Would you like to give Charmander a\n"
	.string "nickname?$"

PalletOakLab_ChooseCharmander_Text_3:
	.string "This ball contains Charmander, the\n"
	.string "Fire-type Pokémon!$"

PalletOakLab_ChooseSquirtle_Text_0:
	.string "This ball contains Squirtle, the\n"
	.string "Water-type Pokémon!\l"
	.string "Would you like to take it with you?$"

PalletOakLab_ChooseSquirtle_Text_1:
	.string "You chose Squirtle!$"

PalletOakLab_ChooseSquirtle_Text_2:
	.string "Would you like to give Squirtle a\n"
	.string "nickname?$"

PalletOakLab_ChooseSquirtle_Text_3:
	.string "This ball contains Squirtle, the\n"
	.string "Water-type Pokémon!$"

PalletOakLab_ScientistTalks_Text_0:
	.string "I'm not the only scientist working for\n"
	.string "Oak. Right now, there are two of us\l"
	.string "left.\l"
	.string "I wonder how Morgan is doing...$"
