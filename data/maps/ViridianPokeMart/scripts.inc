ViridianPokeMart_MapScripts::
	.byte 0


Viridian_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Viridian_Mart_1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end


Viridian_Mart_1:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_POKE_BALL
	.2byte ITEM_NONE
	release
	end
