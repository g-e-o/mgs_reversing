	opt	c+, at+, e+, n-
	section .text

	xdef MENU_ClearRadioTable_8004967C
MENU_ClearRadioTable_8004967C:
	dw 0x27BDFFE8 ; 0x8004967C
	dw 0xAFBF0010 ; 0x80049680
	dw 0x0C012591 ; 0x80049684
	dw 0x00000000 ; 0x80049688
	dw 0x8FBF0010 ; 0x8004968C
	dw 0x00000000 ; 0x80049690
	dw 0x03E00008 ; 0x80049694
	dw 0x27BD0018 ; 0x80049698
