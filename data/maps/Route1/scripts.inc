Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Route1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setvar VAR_0x8001, WEATHER_TEMPERATE
	special SetDynamicWeather
	return

