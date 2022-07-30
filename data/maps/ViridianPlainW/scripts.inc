ViridianPlainW_MapScripts::
	.byte 0


ViridianPlainW_SeasideCottageSign::
	lock
	msgbox ViridianPlainW_SeasideCottageSign_Text_0
	release
	end


ViridianPlainW_TM01::
	lock
	msgbox ViridianPlainW_TM01_Text_0
	setflag FLAG_TM99_TOXIC
	playfanfare MUS_DP_OBTAIN_ITEM
	waitfanfare
	release
	end


ViridianPlainW_SeasideCottageSign_Text_0:
	.string "Viridian Seaside Cottages\lSeeking new tenants!$"

ViridianPlainW_TM01_Text_0:
	.string "Found TM99: Toxic!$"
