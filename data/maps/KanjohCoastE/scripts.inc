KanjohCoastE_MapScripts::
	.byte 0


KanjohCoastE_SandTrigger::
	goto_if_unset FLAG_HIPPOWDON_CAVE_DONE, KanjohCoastE_SandTrigger_2
KanjohCoastE_SandTrigger_1:
	end

KanjohCoastE_SandTrigger_2:
	setweather WEATHER_SANDSTORM
	goto KanjohCoastE_SandTrigger_1

