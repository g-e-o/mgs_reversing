	opt	c+, at+, e+, n-
	section .text

	xdef CdMix
CdMix:
	dw 0x27BDFFE8 ; 0x8008CCC0
	dw 0xAFBF0010 ; 0x8008CCC4
	dw 0x0C023766 ; 0x8008CCC8
	dw 0x00000000 ; 0x8008CCCC
	dw 0x8FBF0010 ; 0x8008CCD0
	dw 0x24020001 ; 0x8008CCD4
	dw 0x03E00008 ; 0x8008CCD8
	dw 0x27BD0018 ; 0x8008CCDC
