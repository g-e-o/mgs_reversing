	opt	c+, at+, e+, n-
	section .text

	xdef gglsight_act_helper_80078054
gglsight_act_helper_80078054:
	dw 0x2884000A ; 0x80078054
	dw 0x97A80010 ; 0x80078058
	dw 0x97A90014 ; 0x8007805C
	dw 0x1480006F ; 0x80078060
	dw 0x3C02800B ; 0x80078064
	dw 0x8C42B928 ; 0x80078068
	dw 0x00000000 ; 0x8007806C
	dw 0x14400006 ; 0x80078070
	dw 0x3C02800B ; 0x80078074
	dw 0x8C42BA50 ; 0x80078078
	dw 0x3C032000 ; 0x8007807C
	dw 0x00431024 ; 0x80078080
	dw 0x10400003 ; 0x80078084
	dw 0x30E20001 ; 0x80078088
	dw 0x00002821 ; 0x8007808C
	dw 0x30E20001 ; 0x80078090
	dw 0x10400034 ; 0x80078094
	dw 0x30A2A000 ; 0x80078098
	dw 0x10400029 ; 0x8007809C
	dw 0x30A22000 ; 0x800780A0
	dw 0x10400014 ; 0x800780A4
	dw 0x30E20004 ; 0x800780A8
	dw 0x14400009 ; 0x800780AC
	dw 0x00091400 ; 0x800780B0
	dw 0x84C30000 ; 0x800780B4
	dw 0x00021403 ; 0x800780B8
	dw 0x0062182A ; 0x800780BC
	dw 0x94C20000 ; 0x800780C0
	dw 0x10600028 ; 0x800780C4
	dw 0x00481021 ; 0x800780C8
	dw 0x0801E05A ; 0x800780CC
	dw 0xA4C20000 ; 0x800780D0
	dw 0x00021403 ; 0x800780D4
	dw 0x84C30000 ; 0x800780D8
	dw 0x00021023 ; 0x800780DC
	dw 0x0043102A ; 0x800780E0
	dw 0x94C30000 ; 0x800780E4
	dw 0x1040001F ; 0x800780E8
	dw 0x00681023 ; 0x800780EC
	dw 0x0801E05A ; 0x800780F0
	dw 0xA4C20000 ; 0x800780F4
	dw 0x1440000A ; 0x800780F8
	dw 0x00091400 ; 0x800780FC
	dw 0x00021403 ; 0x80078100
	dw 0x84C30000 ; 0x80078104
	dw 0x00021023 ; 0x80078108
	dw 0x0043102A ; 0x8007810C
	dw 0x94C30000 ; 0x80078110
	dw 0x10400014 ; 0x80078114
	dw 0x00681023 ; 0x80078118
	dw 0x0801E05A ; 0x8007811C
	dw 0xA4C20000 ; 0x80078120
	dw 0x84C30000 ; 0x80078124
	dw 0x00021403 ; 0x80078128
	dw 0x0062182A ; 0x8007812C
	dw 0x94C20000 ; 0x80078130
	dw 0x1060000C ; 0x80078134
	dw 0x00481021 ; 0x80078138
	dw 0x0801E05A ; 0x8007813C
	dw 0xA4C20000 ; 0x80078140
	dw 0x84C30000 ; 0x80078144
	dw 0x94C20000 ; 0x80078148
	dw 0x18600003 ; 0x8007814C
	dw 0x00000000 ; 0x80078150
	dw 0x0801E059 ; 0x80078154
	dw 0x00481023 ; 0x80078158
	dw 0x04610002 ; 0x8007815C
	dw 0x00481021 ; 0x80078160
	dw 0xA4C20000 ; 0x80078164
	dw 0x30E20002 ; 0x80078168
	dw 0x1040002C ; 0x8007816C
	dw 0x30A25000 ; 0x80078170
	dw 0x10400020 ; 0x80078174
	dw 0x30A24000 ; 0x80078178
	dw 0x10400014 ; 0x8007817C
	dw 0x30E20004 ; 0x80078180
	dw 0x14400009 ; 0x80078184
	dw 0x00091400 ; 0x80078188
	dw 0x84C30002 ; 0x8007818C
	dw 0x00021403 ; 0x80078190
	dw 0x0062182A ; 0x80078194
	dw 0x94C20002 ; 0x80078198
	dw 0x10600020 ; 0x8007819C
	dw 0x00481021 ; 0x800781A0
	dw 0x03E00008 ; 0x800781A4
	dw 0xA4C20002 ; 0x800781A8
	dw 0x00021403 ; 0x800781AC
	dw 0x84C30002 ; 0x800781B0
	dw 0x00021023 ; 0x800781B4
	dw 0x0043102A ; 0x800781B8
	dw 0x94C30002 ; 0x800781BC
	dw 0x10400017 ; 0x800781C0
	dw 0x00681023 ; 0x800781C4
	dw 0x03E00008 ; 0x800781C8
	dw 0xA4C20002 ; 0x800781CC
	dw 0x1040FFF6 ; 0x800781D0
	dw 0x00091400 ; 0x800781D4
	dw 0x84C30002 ; 0x800781D8
	dw 0x00021403 ; 0x800781DC
	dw 0x0062182A ; 0x800781E0
	dw 0x94C20002 ; 0x800781E4
	dw 0x1060000D ; 0x800781E8
	dw 0x00481021 ; 0x800781EC
	dw 0x03E00008 ; 0x800781F0
	dw 0xA4C20002 ; 0x800781F4
	dw 0x84C30002 ; 0x800781F8
	dw 0x94C20002 ; 0x800781FC
	dw 0x18600004 ; 0x80078200
	dw 0x00000000 ; 0x80078204
	dw 0x00481023 ; 0x80078208
	dw 0x03E00008 ; 0x8007820C
	dw 0xA4C20002 ; 0x80078210
	dw 0x04610002 ; 0x80078214
	dw 0x00481021 ; 0x80078218
	dw 0xA4C20002 ; 0x8007821C
	dw 0x03E00008 ; 0x80078220
	dw 0x00000000 ; 0x80078224