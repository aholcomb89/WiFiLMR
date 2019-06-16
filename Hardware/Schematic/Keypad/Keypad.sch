EESchema Schematic File Version 4
LIBS:Keypad-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3850 4000 4000 4000
Wire Wire Line
	2450 3000 2300 3000
$Comp
L power:Earth #PWR0115
U 1 1 5D17A804
P 2250 4400
F 0 "#PWR0115" H 2250 4150 50  0001 C CNN
F 1 "Earth" H 2250 4250 50  0001 C CNN
F 2 "" H 2250 4400 50  0001 C CNN
F 3 "~" H 2250 4400 50  0001 C CNN
	1    2250 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 4100 2250 4100
Wire Wire Line
	2250 4100 2250 4400
$Comp
L Switch:SW_Push UP1
U 1 1 5D17C122
P 6450 2750
F 0 "UP1" H 6450 2943 50  0000 C CNN
F 1 "SW_Push" H 6450 2944 50  0001 C CNN
F 2 "Button_Switch_SMD:SW_SPST_B3S-1000" H 6450 2950 50  0001 C CNN
F 3 "~" H 6450 2950 50  0001 C CNN
	1    6450 2750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push ENTER1
U 1 1 5D17D061
P 6450 3250
F 0 "ENTER1" H 6450 3443 50  0000 C CNN
F 1 "SW_Push" H 6450 3444 50  0001 C CNN
F 2 "Button_Switch_SMD:SW_SPST_B3S-1000" H 6450 3450 50  0001 C CNN
F 3 "~" H 6450 3450 50  0001 C CNN
	1    6450 3250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push DOWN1
U 1 1 5D17D8E5
P 6450 3750
F 0 "DOWN1" H 6450 3943 50  0000 C CNN
F 1 "SW_Push" H 6450 3944 50  0001 C CNN
F 2 "Button_Switch_SMD:SW_SPST_B3S-1000" H 6450 3950 50  0001 C CNN
F 3 "~" H 6450 3950 50  0001 C CNN
	1    6450 3750
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push RIGHT1
U 1 1 5D17DC10
P 7150 3250
F 0 "RIGHT1" H 7150 3443 50  0000 C CNN
F 1 "SW_Push" H 7150 3444 50  0001 C CNN
F 2 "Button_Switch_SMD:SW_SPST_B3S-1000" H 7150 3450 50  0001 C CNN
F 3 "~" H 7150 3450 50  0001 C CNN
	1    7150 3250
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push LEFT1
U 1 1 5D17D4DE
P 5750 3250
F 0 "LEFT1" H 5750 3443 50  0000 C CNN
F 1 "SW_Push" H 5750 3444 50  0001 C CNN
F 2 "Button_Switch_SMD:SW_SPST_B3S-1000" H 5750 3450 50  0001 C CNN
F 3 "~" H 5750 3450 50  0001 C CNN
	1    5750 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 4100 5950 3250
Wire Wire Line
	6650 4100 6650 3750
Connection ~ 6650 3250
Wire Wire Line
	6650 3250 6650 2750
Connection ~ 6650 3750
Wire Wire Line
	6650 3750 6650 3250
Wire Wire Line
	7350 4100 7350 3250
Wire Wire Line
	5550 3250 5550 3350
Wire Wire Line
	6250 3250 6250 3350
Wire Wire Line
	6950 3250 6950 3350
Wire Wire Line
	6950 3350 6250 3350
Connection ~ 6250 3350
Wire Wire Line
	6250 3350 5550 3350
Connection ~ 5550 3350
Wire Wire Line
	6250 2850 5250 2850
Wire Wire Line
	5250 3350 5550 3350
Wire Wire Line
	6250 3850 5250 3850
Wire Wire Line
	6250 2750 6250 2850
Wire Wire Line
	6250 3750 6250 3850
Wire Wire Line
	3850 2900 4000 2900
Wire Wire Line
	3850 3000 4000 3000
Wire Wire Line
	3850 3100 4000 3100
Wire Wire Line
	2450 3300 2300 3300
Wire Wire Line
	2450 3400 2300 3400
Text Label 5250 2850 2    50   ~ 0
ROW0
Text Label 5250 3350 2    50   ~ 0
ROW1
Text Label 5250 3850 2    50   ~ 0
ROW2
Text Label 5950 4100 3    50   ~ 0
COL0
Text Label 6650 4100 3    50   ~ 0
COL1
Text Label 7350 4100 3    50   ~ 0
COL2
Text Label 4000 2900 0    50   ~ 0
COL0
Text Label 4000 3000 0    50   ~ 0
COL1
Text Label 4000 3100 0    50   ~ 0
COL2
Text Label 2300 3400 2    50   ~ 0
ROW2
Wire Wire Line
	2450 2700 2200 2700
$Comp
L power:+3.3V #PWR0116
U 1 1 5D186F12
P 2200 1900
F 0 "#PWR0116" H 2200 1750 50  0001 C CNN
F 1 "+3.3V" H 2215 2073 50  0000 C CNN
F 2 "" H 2200 1900 50  0001 C CNN
F 3 "" H 2200 1900 50  0001 C CNN
	1    2200 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 2900 2450 2900
Wire Wire Line
	3850 2700 3900 2700
Wire Wire Line
	2200 1900 2200 2000
Wire Wire Line
	2200 2250 3900 2250
Wire Wire Line
	2200 2250 2200 2700
$Comp
L Device:R_Small_US R5
U 1 1 5D18A15D
P 3900 2450
F 0 "R5" H 3968 2496 50  0000 L CNN
F 1 "R_Small_US" H 3968 2405 50  0001 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 3900 2450 50  0001 C CNN
F 3 "~" H 3900 2450 50  0001 C CNN
	1    3900 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 2250 3900 2350
Wire Wire Line
	3900 2550 3900 2700
Connection ~ 3900 2700
Wire Wire Line
	3900 2700 4000 2700
$Comp
L Switch:SW_Push PTT1
U 1 1 5D18E70F
P 6450 5100
F 0 "PTT1" H 6450 5293 50  0000 C CNN
F 1 "SW_Push" H 6450 5294 50  0001 C CNN
F 2 "Button_Switch_SMD:SW_SPST_B3S-1000" H 6450 5300 50  0001 C CNN
F 3 "~" H 6450 5300 50  0001 C CNN
	1    6450 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 5600 6650 5100
Wire Wire Line
	6250 5100 6250 5200
Wire Wire Line
	6250 5200 5250 5200
Text Label 5250 5200 2    50   ~ 0
ROW7
Text Label 6650 5600 3    50   ~ 0
COL9
Text Label 4000 3800 0    50   ~ 0
COL9
Text Label 2300 3900 2    50   ~ 0
ROW7
Wire Wire Line
	3850 3800 4000 3800
Wire Wire Line
	2300 3900 2450 3900
NoConn ~ 2450 4200
NoConn ~ 2450 3800
NoConn ~ 2450 3700
NoConn ~ 2450 3600
NoConn ~ 2450 3500
NoConn ~ 3850 3700
NoConn ~ 3850 3600
NoConn ~ 3850 3500
NoConn ~ 3850 3400
NoConn ~ 3850 3300
NoConn ~ 3850 3200
$Comp
L Connector_Generic:Conn_01x02 J9
U 1 1 5D205776
P 2000 2000
F 0 "J9" H 1918 2125 50  0000 C CNN
F 1 "Conn_01x02" H 1918 2126 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2000 2000 50  0001 C CNN
F 3 "~" H 2000 2000 50  0001 C CNN
	1    2000 2000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2200 2250 2200 2100
Connection ~ 2200 2250
Text GLabel 4000 4000 2    50   BiDi ~ 0
SDA|TIM4_CH2
Text Label 2300 3300 2    50   ~ 0
ROW1
Text Label 2300 3200 2    50   ~ 0
ROW0
Wire Wire Line
	2450 3200 2300 3200
$Comp
L parts:TCA8418RTWR-TCA8418RTWR U1
U 1 1 5D178EB2
P 3150 3300
AR Path="/5D178EB2" Ref="U1"  Part="1" 
AR Path="/5D1772AD/5D178EB2" Ref="U1"  Part="1" 
F 0 "U1" H 3150 4270 50  0000 C CNN
F 1 "TCA8418RTWR" H 3150 4179 50  0001 C CNN
F 2 "QFN50P400X400X80-25N" H 3150 3300 50  0001 L BNN
F 3 "" H 3150 3300 50  0001 L BNN
F 4 "None" H 3150 3300 50  0001 L BNN "Field4"
F 5 "Unavailable" H 3150 3300 50  0001 L BNN "Field5"
F 6 "WQFN-24 Texas Instruments" H 3150 3300 50  0001 L BNN "Field6"
F 7 "TCA8418RTWR" H 3150 3300 50  0001 L BNN "Field7"
F 8 "I2C Controlled Keypad Scan IC 24-Pin WQFN EP T/R" H 3150 3300 50  0001 L BNN "Field8"
	1    3150 3300
	1    0    0    -1  
$EndComp
Text GLabel 2300 3000 0    50   BiDi ~ 0
SCL|CAN2_TX|TIM4_CH1
Text GLabel 2300 2900 0    50   BiDi ~ 0
RST
Text GLabel 1850 6900 0    50   Input ~ 0
RST
Text GLabel 1650 6850 0    50   Input ~ 0
SDA|TIM4_CH2
Wire Wire Line
	2050 6950 2050 7000
Wire Wire Line
	3950 6950 3950 7000
Connection ~ 5050 6950
$Comp
L Connector_Generic:Conn_01x32 J2
U 1 1 5D08D824
P 3450 6600
F 0 "J2" V 3575 6546 50  0000 C CNN
F 1 "Conn_01x32" H 3368 8226 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x16_P2.54mm_Horizontal" H 3450 6600 50  0001 C CNN
F 3 "~" H 3450 6600 50  0001 C CNN
	1    3450 6600
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR0102
U 1 1 5D061ED3
P 5300 6950
F 0 "#PWR0102" H 5300 6800 50  0001 C CNN
F 1 "+3.3V" H 5315 7123 50  0000 C CNN
F 2 "" H 5300 6950 50  0001 C CNN
F 3 "" H 5300 6950 50  0001 C CNN
	1    5300 6950
	1    0    0    1   
$EndComp
Wire Wire Line
	5050 6950 5150 6950
Wire Wire Line
	5050 7000 5050 6950
$Comp
L power:Earth #PWR0101
U 1 1 5D05DF38
P 5150 7000
F 0 "#PWR0101" H 5150 6750 50  0001 C CNN
F 1 "Earth" H 5150 6850 50  0001 C CNN
F 2 "" H 5150 7000 50  0001 C CNN
F 3 "~" H 5150 7000 50  0001 C CNN
	1    5150 7000
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1850 6900 4150 6900
$Comp
L Connector_Generic:Conn_01x32 J1
U 1 1 5D05A1AD
P 3450 7200
F 0 "J1" V 3575 7146 50  0000 C CNN
F 1 "Conn_01x32" V 3666 7146 50  0001 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x16_P2.54mm_Horizontal" H 3450 7200 50  0001 C CNN
F 3 "~" H 3450 7200 50  0001 C CNN
	1    3450 7200
	0    -1   1    0   
$EndComp
Wire Wire Line
	3950 6950 2050 6950
Connection ~ 3950 6950
Wire Wire Line
	4250 7000 4250 6900
Wire Wire Line
	4150 7000 4150 6900
Wire Wire Line
	5050 6950 3950 6950
Text GLabel 5350 6850 2    50   Input ~ 0
SCL|CAN2_TX|TIM4_CH1
Wire Wire Line
	3150 6850 3150 7000
Wire Wire Line
	3150 6850 3150 6800
Connection ~ 3150 6850
Wire Wire Line
	2050 6950 2050 6800
Connection ~ 2050 6950
Wire Wire Line
	1950 7000 1950 6800
Wire Wire Line
	2150 7000 2150 6800
Wire Wire Line
	2250 7000 2250 6800
Wire Wire Line
	2350 7000 2350 6800
Wire Wire Line
	2450 7000 2450 6800
Wire Wire Line
	2550 7000 2550 6800
Wire Wire Line
	2650 6800 2650 7000
Wire Wire Line
	2750 7000 2750 6800
Wire Wire Line
	2850 7000 2850 6800
Wire Wire Line
	2950 7000 2950 6800
Wire Wire Line
	3050 7000 3050 6800
Wire Wire Line
	3350 7000 3350 6800
Wire Wire Line
	3450 7000 3450 6800
Wire Wire Line
	3550 7000 3550 6800
Wire Wire Line
	3650 7000 3650 6800
Wire Wire Line
	3750 7000 3750 6800
Wire Wire Line
	3850 7000 3850 6800
Wire Wire Line
	4050 7000 4050 6800
Wire Wire Line
	3950 6950 3950 6800
Wire Wire Line
	4250 6900 4250 6800
Connection ~ 4250 6900
Wire Wire Line
	4150 6900 4150 6800
Connection ~ 4150 6900
Wire Wire Line
	4350 7000 4350 6800
Wire Wire Line
	4450 7000 4450 6800
Wire Wire Line
	4550 7000 4550 6800
Wire Wire Line
	4650 6800 4650 7000
Wire Wire Line
	4750 7000 4750 6800
Wire Wire Line
	4850 6800 4850 7000
Wire Wire Line
	4950 6800 4950 7000
Wire Wire Line
	5050 6950 5050 6800
Wire Wire Line
	1650 6850 3150 6850
Wire Wire Line
	5150 6950 5150 7000
Wire Wire Line
	5300 6900 5300 6950
Wire Wire Line
	4250 6900 5300 6900
Wire Wire Line
	3250 6800 3250 6850
Wire Wire Line
	3250 6850 5350 6850
Connection ~ 3250 6850
Wire Wire Line
	3250 6850 3250 7000
$EndSCHEMATC
