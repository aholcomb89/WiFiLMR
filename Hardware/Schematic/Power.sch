EESchema Schematic File Version 4
LIBS:WiFiLMR-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
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
L Regulator_Linear:L7805 U2
U 1 1 5D21C0D8
P 4000 2500
F 0 "U2" H 4000 2742 50  0000 C CNN
F 1 "L7805" H 4000 2651 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-89-3_Handsoldering" H 4025 2350 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 4000 2450 50  0001 C CNN
	1    4000 2500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0130
U 1 1 5D21C8FB
P 4600 2350
F 0 "#PWR0130" H 4600 2200 50  0001 C CNN
F 1 "+5V" H 4615 2523 50  0000 C CNN
F 2 "" H 4600 2350 50  0001 C CNN
F 3 "" H 4600 2350 50  0001 C CNN
	1    4600 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2500 4450 2500
Wire Wire Line
	4600 2500 4600 2350
$Comp
L power:VCC #PWR0131
U 1 1 5D21D766
P 3350 2350
F 0 "#PWR0131" H 3350 2200 50  0001 C CNN
F 1 "VCC" H 3367 2523 50  0000 C CNN
F 2 "" H 3350 2350 50  0001 C CNN
F 3 "" H 3350 2350 50  0001 C CNN
	1    3350 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 2500 3500 2500
Wire Wire Line
	3350 2500 3350 2350
$Comp
L power:Earth #PWR0132
U 1 1 5D21E006
P 4000 2900
F 0 "#PWR0132" H 4000 2650 50  0001 C CNN
F 1 "Earth" H 4000 2750 50  0001 C CNN
F 2 "" H 4000 2900 50  0001 C CNN
F 3 "~" H 4000 2900 50  0001 C CNN
	1    4000 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2900 4000 2850
$Comp
L Device:C C11
U 1 1 5D21E6E1
P 4450 2700
F 0 "C11" H 4565 2746 50  0000 L CNN
F 1 "1uF" H 4565 2655 50  0000 L CNN
F 2 "Capacitor_SMD:C_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 4488 2550 50  0001 C CNN
F 3 "~" H 4450 2700 50  0001 C CNN
	1    4450 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 5D22084E
P 3500 2700
F 0 "C10" H 3615 2746 50  0000 L CNN
F 1 "1uF" H 3615 2655 50  0000 L CNN
F 2 "Capacitor_SMD:C_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 3538 2550 50  0001 C CNN
F 3 "~" H 3500 2700 50  0001 C CNN
	1    3500 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 2850 4000 2850
Connection ~ 4000 2850
Wire Wire Line
	4000 2850 4000 2800
Wire Wire Line
	4000 2850 3500 2850
Wire Wire Line
	4450 2550 4450 2500
Connection ~ 4450 2500
Wire Wire Line
	4450 2500 4600 2500
Wire Wire Line
	3500 2550 3500 2500
Connection ~ 3500 2500
Wire Wire Line
	3500 2500 3350 2500
$Comp
L Device:R_Small_US R7
U 1 1 5D221D5F
P 5850 2700
F 0 "R7" H 5918 2746 50  0000 L CNN
F 1 "R_Small_US" H 5918 2655 50  0000 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 5850 2700 50  0001 C CNN
F 3 "~" H 5850 2700 50  0001 C CNN
	1    5850 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R8
U 1 1 5D222AC3
P 6650 2700
F 0 "R8" H 6718 2746 50  0000 L CNN
F 1 "R_Small_US" H 6718 2655 50  0000 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 6650 2700 50  0001 C CNN
F 3 "~" H 6650 2700 50  0001 C CNN
	1    6650 2700
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0133
U 1 1 5D222B8C
P 5850 2950
F 0 "#PWR0133" H 5850 2700 50  0001 C CNN
F 1 "Earth" H 5850 2800 50  0001 C CNN
F 2 "" H 5850 2950 50  0001 C CNN
F 3 "~" H 5850 2950 50  0001 C CNN
	1    5850 2950
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0134
U 1 1 5D223737
P 6650 2950
F 0 "#PWR0134" H 6650 2700 50  0001 C CNN
F 1 "Earth" H 6650 2800 50  0001 C CNN
F 2 "" H 6650 2950 50  0001 C CNN
F 3 "~" H 6650 2950 50  0001 C CNN
	1    6650 2950
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0135
U 1 1 5D223881
P 5850 2100
F 0 "#PWR0135" H 5850 1950 50  0001 C CNN
F 1 "+5V" H 5865 2273 50  0000 C CNN
F 2 "" H 5850 2100 50  0001 C CNN
F 3 "" H 5850 2100 50  0001 C CNN
	1    5850 2100
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0136
U 1 1 5D22401D
P 6650 2100
F 0 "#PWR0136" H 6650 1950 50  0001 C CNN
F 1 "+3V3" H 6665 2273 50  0000 C CNN
F 2 "" H 6650 2100 50  0001 C CNN
F 3 "" H 6650 2100 50  0001 C CNN
	1    6650 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D10
U 1 1 5D2243F9
P 5850 2350
F 0 "D10" V 5797 2428 50  0000 L CNN
F 1 "LED" V 5888 2428 50  0000 L CNN
F 2 "Diode_SMD:D_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 5850 2350 50  0001 C CNN
F 3 "~" H 5850 2350 50  0001 C CNN
	1    5850 2350
	0    1    1    0   
$EndComp
$Comp
L Device:LED D11
U 1 1 5D225572
P 6650 2350
F 0 "D11" V 6597 2428 50  0000 L CNN
F 1 "LED" V 6688 2428 50  0000 L CNN
F 2 "Diode_SMD:D_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 6650 2350 50  0001 C CNN
F 3 "~" H 6650 2350 50  0001 C CNN
	1    6650 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	6650 2600 6650 2500
Wire Wire Line
	5850 2600 5850 2500
Wire Wire Line
	5850 2950 5850 2800
Wire Wire Line
	6650 2950 6650 2800
Wire Wire Line
	6650 2200 6650 2100
Wire Wire Line
	5850 2200 5850 2100
$EndSCHEMATC
