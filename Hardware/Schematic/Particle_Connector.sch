EESchema Schematic File Version 4
LIBS:WiFiLMR-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 6
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
F 1 "Conn_01x12" H 5330 3651 50  0001 L CNN
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
F 1 "Conn_01x12" H 5418 3116 50  0001 C CNN
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
	5700 4350 6050 4350
Wire Wire Line
	5700 4250 5800 4250
Wire Wire Line
	5700 4150 6150 4150
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
$Comp
L Connector_Generic:Conn_01x12 J6
U 1 1 5D028600
P 650 3750
F 0 "J6" H 568 4375 50  0000 C CNN
F 1 "Conn_01x12" H 568 4376 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 650 3750 50  0001 C CNN
F 3 "~" H 650 3750 50  0001 C CNN
	1    650  3750
	-1   0    0    -1  
$EndComp
Text Label 9250 3350 2    50   ~ 0
RST
Wire Wire Line
	850  4350 2250 4350
Wire Wire Line
	850  4150 2050 4150
Wire Wire Line
	850  3750 1550 3750
Wire Wire Line
	850  3650 1450 3650
Wire Wire Line
	850  3550 1350 3550
Wire Wire Line
	2250 4500 2250 4350
Wire Wire Line
	2150 4500 2150 4250
Wire Wire Line
	2050 4500 2050 4150
Wire Wire Line
	1950 4500 1950 4050
Wire Wire Line
	850  4050 1950 4050
Wire Wire Line
	1850 4500 1850 3950
Wire Wire Line
	1750 4500 1750 3950
Wire Wire Line
	1550 4500 1550 3750
Wire Wire Line
	1450 4500 1450 3650
Wire Wire Line
	1350 4500 1350 3550
Connection ~ 1350 3550
Wire Wire Line
	1350 3550 2550 3550
$Comp
L Connector_Generic:Conn_01x12 J7
U 1 1 5D05FB25
P 11050 3850
F 0 "J7" H 10968 3117 50  0000 C CNN
F 1 "Conn_01x12" H 10968 3116 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 11050 3850 50  0001 C CNN
F 3 "~" H 11050 3850 50  0001 C CNN
	1    11050 3850
	1    0    0    1   
$EndComp
Wire Wire Line
	9500 4550 9500 4350
Wire Wire Line
	9600 4550 9600 4250
Wire Wire Line
	9700 4550 9700 4150
Wire Wire Line
	9800 4550 9800 4050
Wire Wire Line
	9250 3950 9900 3950
Wire Wire Line
	9250 3850 10000 3850
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
	10200 4550 10200 3750
Wire Wire Line
	10300 4550 10300 3650
Wire Wire Line
	10600 4550 10600 3350
Connection ~ 10600 3350
Wire Wire Line
	10600 3350 10850 3350
Wire Wire Line
	5050 3250 4550 3250
Wire Wire Line
	5700 3650 6150 3650
Wire Wire Line
	5050 3450 4550 3450
Wire Wire Line
	1250 3450 2550 3450
Connection ~ 1250 3450
Wire Wire Line
	1250 4500 1250 3450
Wire Wire Line
	850  4250 2150 4250
Wire Wire Line
	850  3450 1250 3450
$Comp
L power:+5V #PWR0124
U 1 1 5D226B88
P 4550 3150
F 0 "#PWR0124" H 4550 3000 50  0001 C CNN
F 1 "+5V" H 4565 3323 50  0000 C CNN
F 2 "" H 4550 3150 50  0001 C CNN
F 3 "" H 4550 3150 50  0001 C CNN
	1    4550 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3250 4550 3150
$Comp
L power:+5V #PWR0125
U 1 1 5D22A044
P 1150 3150
F 0 "#PWR0125" H 1150 3000 50  0001 C CNN
F 1 "+5V" H 1165 3323 50  0000 C CNN
F 2 "" H 1150 3150 50  0001 C CNN
F 3 "" H 1150 3150 50  0001 C CNN
	1    1150 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  3250 1050 3250
Wire Wire Line
	1150 3250 1150 3150
Wire Wire Line
	1050 4500 1050 3250
Connection ~ 1050 3250
Wire Wire Line
	1050 3250 1150 3250
$Comp
L power:Earth #PWR0126
U 1 1 5D22FE97
P 1350 3350
F 0 "#PWR0126" H 1350 3100 50  0001 C CNN
F 1 "Earth" H 1350 3200 50  0001 C CNN
F 2 "" H 1350 3350 50  0001 C CNN
F 3 "~" H 1350 3350 50  0001 C CNN
	1    1350 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  3350 1150 3350
Wire Wire Line
	1150 4500 1150 3350
Connection ~ 1150 3350
Wire Wire Line
	1150 3350 1350 3350
$Comp
L power:Earth #PWR0127
U 1 1 5D23A38E
P 10100 3550
F 0 "#PWR0127" H 10100 3300 50  0001 C CNN
F 1 "Earth" H 10100 3400 50  0001 C CNN
F 2 "" H 10100 3550 50  0001 C CNN
F 3 "~" H 10100 3550 50  0001 C CNN
	1    10100 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 3550 10400 3550
Wire Wire Line
	10400 4550 10400 3550
Connection ~ 10400 3550
Wire Wire Line
	10400 3550 10850 3550
$Comp
L power:+BATT #PWR0128
U 1 1 5D241656
P 10200 3100
F 0 "#PWR0128" H 10200 2950 50  0001 C CNN
F 1 "+BATT" H 10215 3273 50  0000 C CNN
F 2 "" H 10200 3100 50  0001 C CNN
F 3 "" H 10200 3100 50  0001 C CNN
	1    10200 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	10850 3450 10500 3450
Wire Wire Line
	10200 3450 10200 3100
Wire Wire Line
	10500 4550 10500 3450
Connection ~ 10500 3450
Wire Wire Line
	10500 3450 10200 3450
$Comp
L power:+3V3 #PWR0129
U 1 1 5D24C20C
P 10450 3100
F 0 "#PWR0129" H 10450 2950 50  0001 C CNN
F 1 "+3V3" H 10465 3273 50  0000 C CNN
F 2 "" H 10450 3100 50  0001 C CNN
F 3 "" H 10450 3100 50  0001 C CNN
	1    10450 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	10850 3250 10700 3250
Wire Wire Line
	10450 3250 10450 3100
Wire Wire Line
	10700 4550 10700 3250
Connection ~ 10700 3250
Wire Wire Line
	10700 3250 10450 3250
$Comp
L Device:R_Small_US R9
U 1 1 5D25EAE2
P 5800 4650
F 0 "R9" H 5868 4696 50  0000 L CNN
F 1 "R_Small_US" H 5868 4605 50  0000 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 5800 4650 50  0001 C CNN
F 3 "~" H 5800 4650 50  0001 C CNN
	1    5800 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R10
U 1 1 5D25FB15
P 6050 4900
F 0 "R10" H 6118 4946 50  0000 L CNN
F 1 "R_Small_US" H 6118 4855 50  0000 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 6050 4900 50  0001 C CNN
F 3 "~" H 6050 4900 50  0001 C CNN
	1    6050 4900
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0137
U 1 1 5D2630C7
P 5800 5200
F 0 "#PWR0137" H 5800 5050 50  0001 C CNN
F 1 "+3V3" H 5815 5373 50  0000 C CNN
F 2 "" H 5800 5200 50  0001 C CNN
F 3 "" H 5800 5200 50  0001 C CNN
	1    5800 5200
	1    0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR0138
U 1 1 5D267AA0
P 6050 5200
F 0 "#PWR0138" H 6050 5050 50  0001 C CNN
F 1 "+3V3" H 6065 5373 50  0000 C CNN
F 2 "" H 6050 5200 50  0001 C CNN
F 3 "" H 6050 5200 50  0001 C CNN
	1    6050 5200
	1    0    0    1   
$EndComp
Wire Wire Line
	5800 5200 5800 4750
Wire Wire Line
	5800 4550 5800 4250
Connection ~ 5800 4250
Wire Wire Line
	5800 4250 6150 4250
Wire Wire Line
	6050 4800 6050 4350
Connection ~ 6050 4350
Wire Wire Line
	6050 4350 6150 4350
Wire Wire Line
	6050 5200 6050 5000
$Comp
L Power_Protection:ESDA6V1U1 D4
U 1 1 5CFE731E
P 10400 4750
F 0 "D4" H 10787 4796 50  0000 L CNN
F 1 "ESDA6V1U1" H 10787 4705 50  0000 L CNN
F 2 "ESDA6V1U1:SOIC127P600X175-8N" H 10800 4700 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 10525 4875 50  0001 C CNN
	1    10400 4750
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:ESDA6V1U1 D3
U 1 1 5CFF73FC
P 9700 4750
F 0 "D3" H 10087 4796 50  0000 L CNN
F 1 "ESDA6V1U1" H 10087 4705 50  0000 L CNN
F 2 "ESDA6V1U1:SOIC127P600X175-8N" H 10100 4700 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 9825 4875 50  0001 C CNN
	1    9700 4750
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:ESDA6V1U1 D2
U 1 1 5D000224
P 1950 4700
F 0 "D2" H 2337 4746 50  0000 L CNN
F 1 "ESDA6V1U1" H 2337 4655 50  0000 L CNN
F 2 "ESDA6V1U1:SOIC127P600X175-8N" H 2350 4650 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 2075 4825 50  0001 C CNN
	1    1950 4700
	1    0    0    -1  
$EndComp
$Comp
L Power_Protection:ESDA6V1U1 D1
U 1 1 5D00022A
P 1250 4700
F 0 "D1" H 1637 4746 50  0000 L CNN
F 1 "ESDA6V1U1" H 1637 4655 50  0000 L CNN
F 2 "ESDA6V1U1:SOIC127P600X175-8N" H 1650 4650 50  0001 L CNN
F 3 "http://www.littelfuse.com/~/media/files/littelfuse/technical%20resources/documents/data%20sheets/sp05xxba.pdf" H 1375 4825 50  0001 C CNN
	1    1250 4700
	1    0    0    -1  
$EndComp
Connection ~ 10300 3650
Wire Wire Line
	10300 3650 10850 3650
Wire Wire Line
	9250 3650 10300 3650
Connection ~ 10200 3750
Wire Wire Line
	10200 3750 10850 3750
Wire Wire Line
	9250 3750 10200 3750
Connection ~ 9800 4050
Wire Wire Line
	9800 4050 10850 4050
Wire Wire Line
	9250 4050 9800 4050
Connection ~ 9700 4150
Wire Wire Line
	9700 4150 10850 4150
Wire Wire Line
	9250 4150 9700 4150
Connection ~ 9500 4350
Wire Wire Line
	9500 4350 10850 4350
Connection ~ 9600 4250
Wire Wire Line
	9600 4250 10850 4250
Wire Wire Line
	9250 4350 9500 4350
Wire Wire Line
	9250 4250 9600 4250
Connection ~ 1450 3650
Connection ~ 1550 3750
Connection ~ 1950 4050
Connection ~ 2050 4150
Connection ~ 2150 4250
Connection ~ 2250 4350
Wire Wire Line
	2250 4350 2550 4350
Wire Wire Line
	2150 4250 2550 4250
Wire Wire Line
	2050 4150 2550 4150
Wire Wire Line
	1950 4050 2550 4050
Wire Wire Line
	1550 3750 2550 3750
Wire Wire Line
	1450 3650 2550 3650
Connection ~ 1750 3850
Wire Wire Line
	1750 3850 2550 3850
Connection ~ 1850 3950
Wire Wire Line
	1850 3950 2550 3950
Wire Wire Line
	1750 3950 1750 3850
Wire Wire Line
	850  3850 1750 3850
Wire Wire Line
	850  3950 1850 3950
Text GLabel 6150 4350 2    50   BiDi ~ 0
SDA|TIM4_CH2
Text GLabel 9250 4350 0    50   BiDi ~ 0
SDA|TIM4_CH2
Text GLabel 6150 3650 2    50   BiDi ~ 0
JTAG_TMS
Text GLabel 6150 3750 2    50   BiDi ~ 0
JTAG_TCK
Text GLabel 6150 3850 2    50   BiDi ~ 0
JTAG_TDI|SPI1_SS|I2S3_WS
Text GLabel 6150 3950 2    50   BiDi ~ 0
JTAG_TDO|SPI1_SCK|I2S3_SCK
Text GLabel 6150 4050 2    50   BiDi ~ 0
JTAG_TRST|SPI1_MISO|TIM3_CH1
Text GLabel 6150 4150 2    50   BiDi ~ 0
SPI1_MOSI|CAN2_RX|TIM3_CH2|I2S3_SD
Text GLabel 6150 4250 2    50   BiDi ~ 0
SCL|CAN2_TX|TIM4_CH1
Text GLabel 9250 3650 0    50   BiDi ~ 0
JTAG_TMS
Text GLabel 9250 3750 0    50   BiDi ~ 0
JTAG_TCK
Text GLabel 9250 3850 0    50   BiDi ~ 0
JTAG_TDI|SPI1_SS|I2S3_WS
Text GLabel 9250 3950 0    50   BiDi ~ 0
JTAG_TDO|SPI1_SCK|I2S3_SCK
Text GLabel 9250 4050 0    50   BiDi ~ 0
JTAG_TRST|SPI1_MISO|TIM3_CH1
Text GLabel 9250 4150 0    50   BiDi ~ 0
SPI1_MOSI|CAN2_RX|TIM3_CH2|I2S3_SD
Text GLabel 9250 4250 0    50   BiDi ~ 0
SCL|CAN2_TX|TIM4_CH1
Text GLabel 4550 3450 0    50   BiDi ~ 0
USART1_TX|TIM1_CH2
Text GLabel 4550 3550 0    50   BiDi ~ 0
USART1_RX|TIM1_CH3
Text GLabel 4550 3650 0    50   BiDi ~ 0
WKUP|ADC0|TIM5_CH1
Text GLabel 4550 3750 0    50   BiDi ~ 0
ADC4|DAC1
Text GLabel 4550 3850 0    50   BiDi ~ 0
ADC7|SPI_MOSI|TIM3|CH2
Text GLabel 4550 3950 0    50   BiDi ~ 0
ADC6|SPI_MISO|TIM3_CH1
Text GLabel 4550 4050 0    50   BiDi ~ 0
ADC5|SPI_SCK|DAC2
Text GLabel 4550 4150 0    50   BiDi ~ 0
ADC12|SPI_SS
Text GLabel 4550 4250 0    50   BiDi ~ 0
ADC13
Text GLabel 4550 4350 0    50   BiDi ~ 0
ADC15
Text GLabel 2550 3450 2    50   BiDi ~ 0
USART1_TX|TIM1_CH2
Text GLabel 2550 3550 2    50   BiDi ~ 0
USART1_RX|TIM1_CH3
Text GLabel 2550 3650 2    50   BiDi ~ 0
WKUP|ADC0|TIM5_CH1
Text GLabel 2550 3750 2    50   BiDi ~ 0
ADC4|DAC1
Text GLabel 2550 3850 2    50   BiDi ~ 0
ADC7|SPI_MOSI|TIM3|CH2
Text GLabel 2550 3950 2    50   BiDi ~ 0
ADC6|SPI_MISO|TIM3_CH1
Text GLabel 2550 4050 2    50   BiDi ~ 0
ADC5|SPI_SCK|DAC2
Text GLabel 2550 4150 2    50   BiDi ~ 0
ADC12|SPI_SS
Text GLabel 2550 4250 2    50   BiDi ~ 0
ADC13
Text GLabel 6150 3350 2    50   BiDi ~ 0
RST
$EndSCHEMATC
