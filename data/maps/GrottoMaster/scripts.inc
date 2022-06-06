GrottoMaster_MapScripts::
	.byte 0


GrottoMaster::
	lock
	goto_if_unset FLAG_HAS_GROTTO_LIST, GrottoMaster_2
GrottoMaster_1:
	release
	end

GrottoMaster_2:
	giveitem ITEM_GROTTO_LIST, 1
	setflag FLAG_HAS_GROTTO_LIST
	goto GrottoMaster_1

