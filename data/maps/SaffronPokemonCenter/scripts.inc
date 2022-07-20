SaffronPokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Saffron_PokemonCenter1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0


Saffron_PokemonCenter1F_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end


Saffron_PokemonCenter1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

