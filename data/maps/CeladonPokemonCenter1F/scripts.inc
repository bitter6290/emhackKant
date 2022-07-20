CeladonPokemonCenter1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Celadon_PokemonCenter1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0


Celadon_PokemonCenter1F_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end


Celadon_PokemonCenter1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

