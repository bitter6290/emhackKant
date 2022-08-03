PalletPlayerHouseB1F_MapScripts::
	.byte 0


PalletPlayerHouseB1F_EventScript_WallClock::
	goto_if_set FLAG_SET_WALL_CLOCK, PalletPlayerHouseB1F_EventScript_CheckWallClock
	msgbox PlayersHouse_2F_Text_ClockIsStopped, MSGBOX_DEFAULT
	call PalletPlayerHouseB1F_EventScript_SetWallClock
	delay 30
	setflag FLAG_SET_WALL_CLOCK
	playse SE_EXIT
	releaseall
	end


PalletPlayerHouseB1F_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	waitstate
	return


PalletPlayerHouseB1F_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	waitstate
	releaseall
	end


PalletPlayerHouseB1F_ForceClock::
	goto_if_set FLAG_SET_WALL_CLOCK, PalletPlayerHouseB1F_End
	applymovement OBJ_EVENT_ID_PLAYER, DownExclam
	playse SE_PIN
	msgbox PalletPlayerHouseB1F_ClockNotSet
	applymovement OBJ_EVENT_ID_PLAYER, StepDown
	release
	end


PalletPlayerHouseB1F_End::
	releaseall
	end


StepDown:
	walk_down
	end
	step_end

PalletPlayerHouseB1F_ClockNotSet::
	.string "Ah, wait!\n"
	.string "What's the time?$"
