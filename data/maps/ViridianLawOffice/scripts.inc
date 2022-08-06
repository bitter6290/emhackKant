ViridianLawOffice_MapScripts::
	.byte 0


ViridianLawOffice_Counter::
	lock
	msgbox ViridianLawOffice_Counter_Text_0
	msgbox ViridianLawOffice_Counter_Text_1
	release
	end


ViridianLawOffice_Counter_Text_0:
	.string "Welcome to Viridian Law Offices! Are you\n"
	.string "here to request our services?$"

ViridianLawOffice_Counter_Text_1:
	.string "No? Well, if anyone you know lands in\n"
	.string "the clinic, you know what to do!$"
