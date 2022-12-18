Route1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route1_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Route1_MapScripts_MAP_SCRIPT_ON_LOAD:
	setvar VAR_0x8001, 1
	special SetDynamicWeather
	return


Route1_Lass1::
	.string "Hey, {PLAYER}! How's it going?$"

Route1_Lass2::
	.string "Ooh, you got a Pokémon? What a\n"
	.string "surprise!$"

Route1_Lass3::
	.string "Well, now that we both have Pokémon,\n"
	.string "why don't we try them out?$"
