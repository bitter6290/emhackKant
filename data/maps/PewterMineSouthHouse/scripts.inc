PewterMineSouthHouse_MapScripts::
	.byte 0


PewterMineSHouse_ManDia::
	lock
	goto_if_unset FLAG_TEMP_1, PewterMineSHouse_ManDia_2
	msgbox PewterMineSHouse_ManDia_Text_3
PewterMineSHouse_ManDia_1:
	release
	end

PewterMineSHouse_ManDia_2:
	msgbox PewterMineSHouse_ManDia_Text_0
	faceplayer
	playse SE_PIN
	applymovement 1, PewterMine_Exclam
	waitmovement 1
	msgbox PewterMineSHouse_ManDia_Text_1
	msgbox PewterMineSHouse_ManDia_Text_2
	setflag FLAG_TEMP_1
	goto PewterMineSHouse_ManDia_1


PewterMineSHouse_ManDia_Text_0:
	.string "No... What will I do...$"

PewterMineSHouse_ManDia_Text_1:
	.string "Ah! Who are you?$"

PewterMineSHouse_ManDia_Text_2:
	.string "Professor Oak? An assistant...\l"
	.string "Oh! Yes, she came here yesterday. But\l"
	.string "as you can see, she isn't in here with\l"
	.string "me...\l"
	.string "I can't say for sure, but I think she\l"
	.string "was resting in the building north of\l"
	.string "here when Team Rocket arrived.$"

PewterMineSHouse_ManDia_Text_3:
	.string "I think she was resting in the building\n"
	.string "on the other side of the mine. I\l"
	.string "sincerely hope she hasn't been hurt...$"
