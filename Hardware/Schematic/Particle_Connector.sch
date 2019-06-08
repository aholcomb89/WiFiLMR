EESchema Schematic File Version 4
LIBS:WiFiLMR-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x12 J?
U 1 1 5D02149E
P 5250 3750
AR Path="/5D02149E" Ref="J?"  Part="1" 
AR Path="/5D01AE82/5D02149E" Ref="J1"  Part="1" 
F 0 "J1" H 5330 3742 50  0000 L CNN
F 1 "Conn_01x12" H 5330 3651 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical" H 5250 3750 50  0001 C CNN
F 3 "~" H 5250 3750 50  0001 C CNN
	1    5250 3750
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x12 J?
U 1 1 5D0214A4
P 5500 3850
AR Path="/5D0214A4" Ref="J?"  Part="1" 
AR Path="/5D01AE82/5D0214A4" Ref="J2"  Part="1" 
F 0 "J2" H 5418 3025 50  0000 C CNN
F 1 "Conn_01x12" H 5418 3116 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical" H 5500 3850 50  0001 C CNN
F 3 "~" H 5500 3850 50  0001 C CNN
	1    5500 3850
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5D0214AA
P 5850 3150
AR Path="/5D0214AA" Ref="#PWR?"  Part="1" 
AR Path="/5D01AE82/5D0214AA" Ref="#PWR0102"  Part="1" 
F 0 "#PWR0102" H 5850 3000 50  0001 C CNN
F 1 "+3V3" H 5865 3323 50  0000 C CNN
F 2 "" H 5850 3150 50  0001 C CNN
F 3 "" H 5850 3150 50  0001 C CNN
	1    5850 3150
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 5D0214B0
P 4800 3350
AR Path="/5D0214B0" Ref="#PWR?"  Part="1" 
AR Path="/5D01AE82/5D0214B0" Ref="#PWR0103"  Part="1" 
F 0 "#PWR0103" H 4800 3100 50  0001 C CNN
F 1 "Earth" H 4800 3200 50  0001 C CNN
F 2 "" H 4800 3350 50  0001 C CNN
F 3 "~" H 4800 3350 50  0001 C CNN
	1    4800 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3350 4800 3350
$Comp
L power:Earth #PWR?
U 1 1 5D0214B7
P 5950 3550
AR Path="/5D0214B7" Ref="#PWR?"  Part="1" 
AR Path="/5D01AE82/5D0214B7" Ref="#PWR0104"  Part="1" 
F 0 "#PWR0104" H 5950 3300 50  0001 C CNN
F 1 "Earth" H 5950 3400 50  0001 C CNN
F 2 "" H 5950 3550 50  0001 C CNN
F 3 "~" H 5950 3550 50  0001 C CNN
	1    5950 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3550 5950 3550
Wire Wire Line
	5700 3750 6150 3750
Wire Wire Line
	5700 3850 6150 3850
Wire Wire Line
	5700 3950 6150 3950
Wire Wire Line
	5700 4050 6150 4050
Wire Wire Line
	5700 3350 6150 3350
Text Label 6150 3350 0    50   ~ 0
RST
Text Label 6150 3750 0    50   ~ 0
JTAG_TCK
Text Label 6150 3850 0    50   ~ 0
JTAG_TDI|SPI1_SS|I2S3_WS
Text Label 6150 3950 0    50   ~ 0
JTAG_TDO|SPI1_SCK|I2S3_SCK
Text Label 6150 4050 0    50   ~ 0
JTAG_TRST|SPI1_MISO|TIM3_CH1
Wire Wire Line
	5050 3550 4550 3550
Wire Wire Line
	5050 3650 4550 3650
Wire Wire Line
	5050 3750 4550 3750
Wire Wire Line
	5050 3850 4550 3850
Wire Wire Line
	5050 3950 4550 3950
Wire Wire Line
	5050 4050 4550 4050
Wire Wire Line
	5050 4150 4550 4150
Wire Wire Line
	5050 4250 4550 4250
Wire Wire Line
	5050 4350 4550 4350
Wire Wire Line
	5700 4350 6150 4350
Wire Wire Line
	5700 4250 6150 4250
Wire Wire Line
	5700 4150 6150 4150
Text Label 4550 3450 2    50   ~ 0
USART1_TX|TIM1_CH2
Text Label 4550 3550 2    50   ~ 0
USART1_RX|TIM1_CH3
Text Label 4550 3650 2    50   ~ 0
WKUP|ADC0|TIM5_CH1
Text Label 4550 3750 2    50   ~ 0
ADC4|DAC1
Text Label 4550 4050 2    50   ~ 0
ADC5|SPI_SCK|DAC2
Text Label 4550 4150 2    50   ~ 0
ADC12|SPI_SS
Text Label 4550 4250 2    50   ~ 0
ADC13
Text Label 4550 4350 2    50   ~ 0
ADC15
Text Label 6150 4350 0    50   ~ 0
SDA|TIM4_CH2
Text Label 6150 4250 0    50   ~ 0
SCL|CAN2_TX|TIM4_CH1
Text Label 6150 4150 0    50   ~ 0
SPI1_MOSI|CAN2_RX|TIM3_CH2|I2S3_SD
$Comp
L power:+BATT #PWR?
U 1 1 5D0214E3
P 6100 3150
AR Path="/5D0214E3" Ref="#PWR?"  Part="1" 
AR Path="/5D01AE82/5D0214E3" Ref="#PWR0107"  Part="1" 
F 0 "#PWR0107" H 6100 3000 50  0001 C CNN
F 1 "+BATT" H 6115 3323 50  0000 C CNN
F 2 "" H 6100 3150 50  0001 C CNN
F 3 "" H 6100 3150 50  0001 C CNN
	1    6100 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3250 5850 3250
Wire Wire Line
	5850 3250 5850 3150
Wire Wire Line
	5700 3450 6100 3450
Wire Wire Line
	6100 3450 6100 3150
Text Label 4550 3950 2    50   ~ 0
ADC6|SPI_MISO|TIM3_CH1
Text Label 4550 3850 2    50   ~ 0
ADC7|SPI_MOSI|TIM3_CH2
$Comp
L Connector_Generic:Conn_01x12 J6
U 1 1 5D028600
P 650 3750
F 0 "J6" H 568 4467 50  0000 C CNN
F 1 "Conn_01x12" H 568 4376 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 650 3750 50  0001 C CNN
F 3 "~" H 650 3750 50  0001 C CNN
	1    650  3750
	-1   0    0    -1  
$EndComp
Text Label 9250 3350 2    50   ~ 0
RST
Text Label 9250 3750 2    50   ~ 0
JTAG_TCK
Text Label 9250 3850 2    50   ~ 0
JTAG_TDI|SPI1_SS|I2S3_WS
Text Label 9250 3950 2    50   ~ 0
JTAG_TDO|SPI1_SCK|I2S3_SCK
Text Label 9250 4050 2    50   ~ 0
JTAG_TRST|SPI1_MISO|TIM3_CH1
Text Label 9250 4350 2    50   ~ 0
SDA|TIM4_CH2
Text Label 9250 4250 2    50   ~ 0
SCL|CAN2_TX|TIM4_CH1
Text Label 9250 4150 2    50   ~ 0
SPI1_MOSI|CAN2_RX|TIM3_CH2|I2S3_SD
Wire Wire Line
	9250 4350 9400 4350
Wire Wire Line
	9250 4050 9700 4050
$Comp
L Power_Protection:SP0504BAHT D1
U 1 1 5D08FF95
P 1150 4700
F 0 "D1" H 1455 4746 50  0000 L CNN
F 1 "SP0504BAHT" H 1455 4655 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 1450 4650 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 1275 4825 50  0001 C CNN
	1    1150 4700
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0504BAHT D2
U 1 1 5D0923F6
P 1650 4700
F 0 "D2" H 1955 4746 50  0000 L CNN
F 1 "SP0504BAHT" H 1955 4655 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 1950 4650 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 1775 4825 50  0001 C CNN
	1    1650 4700
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0504BAHT D3
U 1 1 5D094338
P 2150 4700
F 0 "D3" H 2455 4746 50  0000 L CNN
F 1 "SP0504BAHT" H 2455 4655 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 2450 4650 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 2275 4825 50  0001 C CNN
	1    2150 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 5000 1650 4900
Wire Wire Line
	1150 5000 1150 4900
$Comp
L power:Earth #PWR0109
U 1 1 5D05AE35
P 1650 5000
F 0 "#PWR0109" H 1650 4750 50  0001 C CNN
F 1 "Earth" H 1650 4850 50  0001 C CNN
F 2 "" H 1650 5000 50  0001 C CNN
F 3 "~" H 1650 5000 50  0001 C CNN
	1    1650 5000
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0110
U 1 1 5D0595E5
P 1150 5000
F 0 "#PWR0110" H 1150 4750 50  0001 C CNN
F 1 "Earth" H 1150 4850 50  0001 C CNN
F 2 "" H 1150 5000 50  0001 C CNN
F 3 "~" H 1150 5000 50  0001 C CNN
	1    1150 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 5000 2150 4900
$Comp
L power:Earth #PWR0111
U 1 1 5D0A1661
P 2150 5000
F 0 "#PWR0111" H 2150 4750 50  0001 C CNN
F 1 "Earth" H 2150 4850 50  0001 C CNN
F 2 "" H 2150 5000 50  0001 C CNN
F 3 "~" H 2150 5000 50  0001 C CNN
	1    2150 5000
	1    0    0    -1  
$EndComp
Text Label 2550 3850 0    50   ~ 0
ADC7|SPI_MOSI|TIM3_CH2
Text Label 2550 3950 0    50   ~ 0
ADC6|SPI_MISO|TIM3_CH1
Text Label 2550 4350 0    50   ~ 0
ADC15
Text Label 2550 4250 0    50   ~ 0
ADC13
Text Label 2550 4150 0    50   ~ 0
ADC12|SPI_SS
Text Label 2550 4050 0    50   ~ 0
ADC5|SPI_SCK|DAC2
Text Label 2550 3750 0    50   ~ 0
ADC4|DAC1
Text Label 2550 3650 0    50   ~ 0
WKUP|ADC0|TIM5_CH1
Text Label 2550 3550 0    50   ~ 0
USART1_RX|TIM1_CH3
Wire Wire Line
	850  4350 2350 4350
Wire Wire Line
	850  4150 2150 4150
Wire Wire Line
	850  3950 1850 3950
Wire Wire Line
	850  3850 1750 3850
Wire Wire Line
	850  3750 1650 3750
Wire Wire Line
	850  3650 1550 3650
Wire Wire Line
	850  3550 1350 3550
Wire Wire Line
	2350 4500 2350 4350
Connection ~ 2350 4350
Wire Wire Line
	2350 4350 2550 4350
Wire Wire Line
	2250 4500 2250 4250
Connection ~ 2250 4250
Wire Wire Line
	2250 4250 2550 4250
Wire Wire Line
	2150 4500 2150 4150
Connection ~ 2150 4150
Wire Wire Line
	2150 4150 2550 4150
Wire Wire Line
	2050 4500 2050 4050
Wire Wire Line
	850  4050 2050 4050
Connection ~ 2050 4050
Wire Wire Line
	2050 4050 2550 4050
Wire Wire Line
	1850 4500 1850 3950
Connection ~ 1850 3950
Wire Wire Line
	1850 3950 2550 3950
Wire Wire Line
	1750 4500 1750 3850
Connection ~ 1750 3850
Wire Wire Line
	1750 3850 2550 3850
Wire Wire Line
	1650 4500 1650 3750
Connection ~ 1650 3750
Wire Wire Line
	1650 3750 2550 3750
Wire Wire Line
	1550 4500 1550 3650
Connection ~ 1550 3650
Wire Wire Line
	1550 3650 2550 3650
Wire Wire Line
	1350 4500 1350 3550
Connection ~ 1350 3550
Wire Wire Line
	1350 3550 2550 3550
$Comp
L power:Earth #PWR0112
U 1 1 5D0E4472
P 10500 5050
F 0 "#PWR0112" H 10500 4800 50  0001 C CNN
F 1 "Earth" H 10500 4900 50  0001 C CNN
F 2 "" H 10500 5050 50  0001 C CNN
F 3 "~" H 10500 5050 50  0001 C CNN
	1    10500 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10500 5050 10500 4950
$Comp
L power:Earth #PWR0113
U 1 1 5D0E446B
P 9500 5050
F 0 "#PWR0113" H 9500 4800 50  0001 C CNN
F 1 "Earth" H 9500 4900 50  0001 C CNN
F 2 "" H 9500 5050 50  0001 C CNN
F 3 "~" H 9500 5050 50  0001 C CNN
	1    9500 5050
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0114
U 1 1 5D0E4465
P 10000 5050
F 0 "#PWR0114" H 10000 4800 50  0001 C CNN
F 1 "Earth" H 10000 4900 50  0001 C CNN
F 2 "" H 10000 5050 50  0001 C CNN
F 3 "~" H 10000 5050 50  0001 C CNN
	1    10000 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 5050 9500 4950
Wire Wire Line
	10000 5050 10000 4950
$Comp
L Power_Protection:SP0504BAHT D6
U 1 1 5D0E445D
P 10500 4750
F 0 "D6" H 10805 4796 50  0000 L CNN
F 1 "SP0504BAHT" H 10805 4705 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 10800 4700 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 10625 4875 50  0001 C CNN
	1    10500 4750
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0504BAHT D5
U 1 1 5D0E4457
P 10000 4750
F 0 "D5" H 10305 4796 50  0000 L CNN
F 1 "SP0504BAHT" H 10305 4705 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 10300 4700 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 10125 4875 50  0001 C CNN
	1    10000 4750
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:SP0504BAHT D4
U 1 1 5D0E4451
P 9500 4750
F 0 "D4" H 9805 4796 50  0000 L CNN
F 1 "SP0504BAHT" H 9805 4705 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 9800 4700 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 9625 4875 50  0001 C CNN
	1    9500 4750
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x12 J7
U 1 1 5D05FB25
P 11050 3850
F 0 "J7" H 10968 3025 50  0000 C CNN
F 1 "Conn_01x12" H 10968 3116 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 11050 3850 50  0001 C CNN
F 3 "~" H 11050 3850 50  0001 C CNN
	1    11050 3850
	1    0    0    1   
$EndComp
Wire Wire Line
	9400 4550 9400 4350
Connection ~ 9400 4350
Wire Wire Line
	9500 4550 9500 4250
Wire Wire Line
	9250 4250 9500 4250
Connection ~ 9500 4250
Wire Wire Line
	9600 4550 9600 4150
Connection ~ 9600 4150
Wire Wire Line
	9600 4150 9250 4150
Wire Wire Line
	9700 4550 9700 4050
Connection ~ 9700 4050
Wire Wire Line
	9400 4350 10850 4350
Wire Wire Line
	9500 4250 10850 4250
Wire Wire Line
	9600 4150 10850 4150
Wire Wire Line
	9700 4050 10850 4050
Wire Wire Line
	9250 3950 9900 3950
Wire Wire Line
	9250 3850 10000 3850
Wire Wire Line
	9250 3750 10100 3750
Wire Wire Line
	9250 3350 10600 3350
Wire Wire Line
	9900 4550 9900 3950
Connection ~ 9900 3950
Wire Wire Line
	9900 3950 10850 3950
Wire Wire Line
	10000 4550 10000 3850
Connection ~ 10000 3850
Wire Wire Line
	10000 3850 10850 3850
Wire Wire Line
	10100 4550 10100 3750
Connection ~ 10100 3750
Wire Wire Line
	10100 3750 10850 3750
Wire Wire Line
	10200 4550 10200 3650
Connection ~ 10200 3650
Wire Wire Line
	10200 3650 10850 3650
Wire Wire Line
	10600 4550 10600 3350
Connection ~ 10600 3350
Wire Wire Line
	10600 3350 10850 3350
Wire Wire Line
	5050 3250 4550 3250
Wire Wire Line
	9250 3650 10200 3650
Wire Wire Line
	5700 3650 6150 3650
Text Label 9250 3650 2    50   ~ 0
JTAG_TMS
Text Label 6150 3650 0    50   ~ 0
JTAG_TMS
Wire Wire Line
	5050 3450 4550 3450
Wire Wire Line
	1250 3450 2550 3450
Connection ~ 1250 3450
Text Label 2550 3450 0    50   ~ 0
USART1_TX|TIM1_CH2
Wire Wire Line
	1250 4500 1250 3450
Wire Wire Line
	850  4250 2250 4250
Wire Wire Line
	850  3450 1250 3450
$EndSCHEMATC
