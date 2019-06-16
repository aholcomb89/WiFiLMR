EESchema Schematic File Version 4
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
$Comp
L Connector_Generic:Conn_01x24 J8
U 1 1 5D19681B
P 8100 3550
F 0 "J8" H 8180 3496 50  0000 L CNN
F 1 "Conn_01x24" H 8180 3451 50  0001 L CNN
F 2 "Connector_FFC-FPC:Hirose_FH12-24S-0.5SH_1x24-1MP_P0.50mm_Horizontal" H 8100 3550 50  0001 C CNN
F 3 "~" H 8100 3550 50  0001 C CNN
	1    8100 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2450 7700 2450
Wire Wire Line
	7900 2750 7700 2750
Wire Wire Line
	7900 2850 7700 2850
Wire Wire Line
	7900 2950 7700 2950
Wire Wire Line
	7900 3050 7700 3050
Wire Wire Line
	7900 4250 7700 4250
NoConn ~ 7700 2450
NoConn ~ 7700 2750
NoConn ~ 7700 2850
NoConn ~ 7700 2950
NoConn ~ 7700 3050
NoConn ~ 7700 4250
$Comp
L Device:D_Schottky D9
U 1 1 5D199829
P 6800 5100
F 0 "D9" H 6800 5224 50  0000 C CNN
F 1 "D_Schottky" H 6800 5225 50  0001 C CNN
F 2 "Diode_SMD:D_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 6800 5100 50  0001 C CNN
F 3 "~" H 6800 5100 50  0001 C CNN
	1    6800 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D7
U 1 1 5D19AE7A
P 6350 5400
F 0 "D7" V 6350 5321 50  0000 R CNN
F 1 "D_Schottky" V 6305 5321 50  0001 R CNN
F 2 "Diode_SMD:D_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 6350 5400 50  0001 C CNN
F 3 "~" H 6350 5400 50  0001 C CNN
	1    6350 5400
	0    -1   -1   0   
$EndComp
$Comp
L power:Earth #PWR0117
U 1 1 5D19B975
P 6350 5600
F 0 "#PWR0117" H 6350 5350 50  0001 C CNN
F 1 "Earth" H 6350 5450 50  0001 C CNN
F 2 "" H 6350 5600 50  0001 C CNN
F 3 "~" H 6350 5600 50  0001 C CNN
	1    6350 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 5D19C56B
P 7700 5300
F 0 "C9" H 7815 5346 50  0000 L CNN
F 1 "1uF" H 7815 5255 50  0000 L CNN
F 2 "Capacitor_SMD:C_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 7738 5150 50  0001 C CNN
F 3 "~" H 7700 5300 50  0001 C CNN
	1    7700 5300
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D8
U 1 1 5D19DABA
P 6600 4250
F 0 "D8" V 6600 4171 50  0000 R CNN
F 1 "D_Schottky" V 6555 4171 50  0001 R CNN
F 2 "Diode_SMD:D_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 6600 4250 50  0001 C CNN
F 3 "~" H 6600 4250 50  0001 C CNN
	1    6600 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C4
U 1 1 5D19E7E6
P 6600 4650
F 0 "C4" H 6715 4696 50  0000 L CNN
F 1 "1uF" H 6715 4605 50  0000 L CNN
F 2 "Capacitor_SMD:C_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 6638 4500 50  0001 C CNN
F 3 "~" H 6600 4650 50  0001 C CNN
	1    6600 4650
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0118
U 1 1 5D1A050B
P 7150 4800
F 0 "#PWR0118" H 7150 4550 50  0001 C CNN
F 1 "Earth" H 7150 4650 50  0001 C CNN
F 2 "" H 7150 4800 50  0001 C CNN
F 3 "~" H 7150 4800 50  0001 C CNN
	1    7150 4800
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0119
U 1 1 5D1A0989
P 7700 5550
F 0 "#PWR0119" H 7700 5300 50  0001 C CNN
F 1 "Earth" H 7700 5400 50  0001 C CNN
F 2 "" H 7700 5550 50  0001 C CNN
F 3 "~" H 7700 5550 50  0001 C CNN
	1    7700 5550
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0120
U 1 1 5D1A0F8F
P 5750 5050
F 0 "#PWR0120" H 5750 4800 50  0001 C CNN
F 1 "Earth" H 5750 4900 50  0001 C CNN
F 2 "" H 5750 5050 50  0001 C CNN
F 3 "~" H 5750 5050 50  0001 C CNN
	1    5750 5050
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0121
U 1 1 5D1A1379
P 5450 5050
F 0 "#PWR0121" H 5450 4800 50  0001 C CNN
F 1 "Earth" H 5450 4900 50  0001 C CNN
F 2 "" H 5450 5050 50  0001 C CNN
F 3 "~" H 5450 5050 50  0001 C CNN
	1    5450 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5D1A1C14
P 5750 4800
F 0 "C2" H 5865 4846 50  0000 L CNN
F 1 "1uF" H 5865 4755 50  0000 L CNN
F 2 "Capacitor_SMD:C_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 5788 4650 50  0001 C CNN
F 3 "~" H 5750 4800 50  0001 C CNN
	1    5750 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5D1A1D43
P 5450 4800
F 0 "C1" H 5565 4846 50  0000 L CNN
F 1 "0.1uF" H 5565 4755 50  0000 L CNN
F 2 "Capacitor_SMD:C_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 5488 4650 50  0001 C CNN
F 3 "~" H 5450 4800 50  0001 C CNN
	1    5450 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5D1A2124
P 6350 4800
F 0 "C3" H 6465 4846 50  0000 L CNN
F 1 "4.7uF" H 6465 4755 50  0000 L CNN
F 2 "Capacitor_SMD:C_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 6388 4650 50  0001 C CNN
F 3 "~" H 6350 4800 50  0001 C CNN
	1    6350 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5D1A3873
P 7350 4750
F 0 "C5" V 7602 4750 50  0000 C CNN
F 1 "1uF" V 7511 4750 50  0000 C CNN
F 2 "Capacitor_SMD:C_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 7388 4600 50  0001 C CNN
F 3 "~" H 7350 4750 50  0001 C CNN
	1    7350 4750
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C8
U 1 1 5D1A48D0
P 7600 4550
F 0 "C8" V 7852 4550 50  0000 C CNN
F 1 "1uF" V 7761 4550 50  0000 C CNN
F 2 "Capacitor_SMD:C_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 7638 4400 50  0001 C CNN
F 3 "~" H 7600 4550 50  0001 C CNN
	1    7600 4550
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C7
U 1 1 5D1A4CCB
P 7500 4350
F 0 "C7" V 7752 4350 50  0000 C CNN
F 1 "1uF" V 7661 4350 50  0000 C CNN
F 2 "Capacitor_SMD:C_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 7538 4200 50  0001 C CNN
F 3 "~" H 7500 4350 50  0001 C CNN
	1    7500 4350
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C6
U 1 1 5D1A4FFC
P 7400 4150
F 0 "C6" V 7652 4150 50  0000 C CNN
F 1 "1uF" V 7561 4150 50  0000 C CNN
F 2 "Capacitor_SMD:C_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 7438 4000 50  0001 C CNN
F 3 "~" H 7400 4150 50  0001 C CNN
	1    7400 4150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7500 4750 7900 4750
Wire Wire Line
	7150 4800 7150 4750
Wire Wire Line
	7150 4750 7200 4750
Wire Wire Line
	7450 4550 7150 4550
Wire Wire Line
	7150 4550 7150 4750
Connection ~ 7150 4750
Wire Wire Line
	7350 4350 7150 4350
Wire Wire Line
	7150 4350 7150 4550
Connection ~ 7150 4550
Wire Wire Line
	7250 4150 7150 4150
Wire Wire Line
	7150 4150 7150 4350
Connection ~ 7150 4350
Wire Wire Line
	7750 4550 7900 4550
Wire Wire Line
	7650 4350 7900 4350
Wire Wire Line
	7550 4150 7900 4150
Wire Wire Line
	7900 4650 7700 4650
Wire Wire Line
	7700 5450 7700 5550
Wire Wire Line
	6650 5100 6350 5100
Wire Wire Line
	6350 5100 6350 5250
Wire Wire Line
	6350 5600 6350 5550
Wire Wire Line
	6600 4500 6600 4450
$Comp
L power:Earth #PWR0122
U 1 1 5D1B2D75
P 6600 4850
F 0 "#PWR0122" H 6600 4600 50  0001 C CNN
F 1 "Earth" H 6600 4700 50  0001 C CNN
F 2 "" H 6600 4850 50  0001 C CNN
F 3 "~" H 6600 4850 50  0001 C CNN
	1    6600 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 4850 6600 4800
Wire Wire Line
	7900 4450 6600 4450
Connection ~ 6600 4450
Wire Wire Line
	6600 4450 6600 4400
Wire Wire Line
	7700 4650 7700 5100
Wire Wire Line
	6950 5100 7700 5100
Connection ~ 7700 5100
Wire Wire Line
	7700 5100 7700 5150
Wire Wire Line
	6350 5100 6350 4950
Connection ~ 6350 5100
Wire Wire Line
	6350 4650 6350 4100
Wire Wire Line
	6350 4100 6600 4100
$Comp
L Device:L L1
U 1 1 5D1B9596
P 6050 4100
F 0 "L1" V 6240 4100 50  0000 C CNN
F 1 "10uH" V 6149 4100 50  0000 C CNN
F 2 "Inductor_SMD:L_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 6050 4100 50  0001 C CNN
F 3 "~" H 6050 4100 50  0001 C CNN
	1    6050 4100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 4650 5750 4100
Wire Wire Line
	7900 3850 7800 3850
Wire Wire Line
	5750 3850 5750 4100
Connection ~ 5750 4100
Wire Wire Line
	7900 3950 7800 3950
Wire Wire Line
	7800 3950 7800 3850
Connection ~ 7800 3850
Wire Wire Line
	7800 3850 5750 3850
Wire Wire Line
	5450 4650 5750 4650
Connection ~ 5750 4650
Wire Wire Line
	5750 5050 5750 4950
Wire Wire Line
	5450 5050 5450 4950
$Comp
L Device:R_Small_US R6
U 1 1 5D1C2A00
P 6900 2750
F 0 "R6" V 7105 2750 50  0000 C CNN
F 1 "470mOhms" V 7014 2750 50  0000 C CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 6900 2750 50  0001 C CNN
F 3 "~" H 6900 2750 50  0001 C CNN
	1    6900 2750
	0    -1   -1   0   
$EndComp
$Comp
L Device:Q_PJFET_GSD Q1
U 1 1 5D1C4220
P 7450 2550
F 0 "Q1" H 7641 2550 50  0000 L CNN
F 1 "Q_PJFET_GSD" H 7641 2505 50  0001 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7650 2650 50  0001 C CNN
F 3 "~" H 7450 2550 50  0001 C CNN
	1    7450 2550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7900 2550 7650 2550
Wire Wire Line
	7900 2650 7600 2650
Wire Wire Line
	7600 2650 7600 2750
Wire Wire Line
	7600 2750 7350 2750
Connection ~ 7350 2750
Wire Wire Line
	7150 4150 7150 4050
Wire Wire Line
	6750 2850 6750 2750
Wire Wire Line
	6750 2750 6800 2750
Connection ~ 7150 4150
Wire Wire Line
	6600 4100 6600 2300
Wire Wire Line
	6600 2300 7350 2300
Wire Wire Line
	7350 2300 7350 2350
Connection ~ 6600 4100
Wire Wire Line
	5450 4650 4800 4650
Connection ~ 5450 4650
Wire Wire Line
	7900 3250 4800 3250
Wire Wire Line
	7900 3350 4800 3350
Wire Wire Line
	7900 3450 4800 3450
Wire Wire Line
	7900 3550 4800 3550
Wire Wire Line
	7900 3650 4800 3650
Wire Wire Line
	7900 3750 4800 3750
$Comp
L power:+3.3V #PWR0123
U 1 1 5D1E7AF8
P 4700 4550
F 0 "#PWR0123" H 4700 4400 50  0001 C CNN
F 1 "+3.3V" H 4715 4723 50  0000 C CNN
F 2 "" H 4700 4550 50  0001 C CNN
F 3 "" H 4700 4550 50  0001 C CNN
	1    4700 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 4650 4700 4550
Text Label 4800 3450 2    50   ~ 0
DISP_DC
Text Label 4800 3250 2    50   ~ 0
DISP_BUSY
Wire Wire Line
	7900 4050 7150 4050
Connection ~ 7150 4050
Wire Wire Line
	7150 4050 7150 3150
Wire Wire Line
	7900 3150 7150 3150
Connection ~ 7150 3150
Wire Wire Line
	7150 3150 7150 2850
$Comp
L Connector_Generic:Conn_01x02 J10
U 1 1 5D1F7A76
P 4800 4850
F 0 "J10" V 4718 4930 50  0000 L CNN
F 1 "Conn_01x02" V 4763 4930 50  0001 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4800 4850 50  0001 C CNN
F 3 "~" H 4800 4850 50  0001 C CNN
	1    4800 4850
	0    1    1    0   
$EndComp
Wire Wire Line
	5750 4100 5900 4100
Wire Wire Line
	6200 4100 6350 4100
Connection ~ 6350 4100
Wire Wire Line
	7000 2750 7350 2750
Wire Wire Line
	6750 2850 7150 2850
Text GLabel 4800 3750 0    50   BiDi ~ 0
ADC7|SPI_MOSI|TIM3|CH2
Text GLabel 4800 3650 0    50   BiDi ~ 0
ADC5|SPI_SCK|DAC2
Text GLabel 4800 3550 0    50   BiDi ~ 0
ADC12|SPI_SS
Text GLabel 4800 3350 0    50   BiDi ~ 0
RST
$Comp
L Connector_Generic:Conn_01x32 J1
U 1 1 5D06E94D
P 3500 7000
F 0 "J1" V 3625 6946 50  0000 C CNN
F 1 "Conn_01x32" V 3716 6946 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x16_P2.54mm_Horizontal" H 3500 7000 50  0001 C CNN
F 3 "~" H 3500 7000 50  0001 C CNN
	1    3500 7000
	0    1    1    0   
$EndComp
$Comp
L power:Earth #PWR0101
U 1 1 5D074B64
P 1600 6550
F 0 "#PWR0101" H 1600 6300 50  0001 C CNN
F 1 "Earth" H 1600 6400 50  0001 C CNN
F 2 "" H 1600 6550 50  0001 C CNN
F 3 "~" H 1600 6550 50  0001 C CNN
	1    1600 6550
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 6800 1900 6650
Wire Wire Line
	1900 6550 1600 6550
Wire Wire Line
	1900 6650 3000 6650
Wire Wire Line
	3000 6650 3000 6800
Connection ~ 1900 6650
Wire Wire Line
	1900 6650 1900 6550
Wire Wire Line
	3000 6650 4900 6650
Wire Wire Line
	4900 6650 4900 6800
Connection ~ 3000 6650
$Comp
L power:+3.3V #PWR0102
U 1 1 5D08108E
P 2700 6350
F 0 "#PWR0102" H 2700 6200 50  0001 C CNN
F 1 "+3.3V" H 2715 6523 50  0000 C CNN
F 2 "" H 2700 6350 50  0001 C CNN
F 3 "" H 2700 6350 50  0001 C CNN
	1    2700 6350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 6800 2700 6350
Wire Wire Line
	2800 6800 2800 6350
Wire Wire Line
	4100 6800 4100 6350
Wire Wire Line
	4200 6800 4200 6350
Wire Wire Line
	4400 6800 4400 6350
Text GLabel 2800 6350 1    50   Input ~ 0
RST
Text GLabel 4100 6350 1    50   Input ~ 0
ADC12|SPI_SS
Text GLabel 4200 6350 1    50   Input ~ 0
ADC5|SPI_SCK|DAC2
Text GLabel 4400 6350 1    50   Input ~ 0
ADC7|SPI_MOSI|TIM3|CH2
NoConn ~ 2000 6800
NoConn ~ 2100 6800
NoConn ~ 2200 6800
NoConn ~ 2300 6800
NoConn ~ 2400 6800
NoConn ~ 2500 6800
NoConn ~ 2600 6800
NoConn ~ 2900 6800
NoConn ~ 3100 6800
NoConn ~ 3200 6800
NoConn ~ 3300 6800
NoConn ~ 3400 6800
NoConn ~ 3500 6800
NoConn ~ 3600 6800
NoConn ~ 3700 6800
NoConn ~ 3800 6800
NoConn ~ 3900 6800
NoConn ~ 4000 6800
NoConn ~ 4300 6800
NoConn ~ 4500 6800
NoConn ~ 4600 6800
NoConn ~ 4700 6800
NoConn ~ 4800 6800
NoConn ~ 5000 6800
$EndSCHEMATC
