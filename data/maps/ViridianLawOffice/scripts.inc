ViridianLawOffice_MapScripts::
	.byte 0


ViridianLawOffice_Counter::
	lock
	msgbox ViridianLawOffice_Counter_Text_0
	msgbox ViridianLawOffice_Counter_Text_1
	release
	end


ViridianLawOffice_Counter_Text_0:
	.string "Welcome to Viridian Law Office! Are you\n"
	.string "here to request our services?$"

ViridianLawOffice_Counter_Text_1:
	.string "No? Well, if you know anyone in the\n"
	.string "clinic down the street, make sure you\l"
	.string "send them here!$"
