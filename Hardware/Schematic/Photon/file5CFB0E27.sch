EESchema Schematic File Version 4
LIBS:WiFiLMR-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 5100 3850 0    50   ~ 0
JTAG_TDO|SPI1_SCK|I2S3_SCK
Wire Wire Line
	4200 3750 4200 4150
Wire Wire Line
	4000 3750 4200 3750
Text Label 5100 3950 0    50   ~ 0
RST
Wire Wire Line
	4000 3950 5100 3950
Wire Wire Line
	4000 3850 5100 3850
Text Label 5100 3650 0    50   ~ 0
JTAG_TCK
Text Label 5100 3550 0    50   ~ 0
JTAG_TMS
Text Label 5100 3450 0    50   ~ 0
JTAG_TDI|SPI1_SS|I2S3_WS
Text Label 5100 3350 0    50   ~ 0
JTAG_TRST|SPI1_MISO|TIM3_CH1
Wire Wire Line
	3300 4150 3300 4200
Connection ~ 3300 4150
Wire Wire Line
	3500 4150 3300 4150
Connection ~ 3300 4050
Wire Wire Line
	3300 4050 3300 4150
Wire Wire Line
	3300 3450 3300 3550
Connection ~ 3300 3450
Wire Wire Line
	3500 3450 3300 3450
Wire Wire Line
	3300 3550 3300 3650
Connection ~ 3300 3550
Wire Wire Line
	3500 3550 3300 3550
Wire Wire Line
	3300 3650 3300 3750
Connection ~ 3300 3650
Wire Wire Line
	3500 3650 3300 3650
Wire Wire Line
	3300 3750 3300 3850
Connection ~ 3300 3750
Wire Wire Line
	3500 3750 3300 3750
Wire Wire Line
	3300 3850 3300 3950
Connection ~ 3300 3850
Wire Wire Line
	3500 3850 3300 3850
Wire Wire Line
	3300 3950 3300 4050
Connection ~ 3300 3950
Wire Wire Line
	3500 3950 3300 3950
Wire Wire Line
	3500 4050 3300 4050
Wire Wire Line
	3300 3350 3300 3450
Wire Wire Line
	3500 3350 3300 3350
Connection ~ 4850 3650
Wire Wire Line
	4850 3650 5100 3650
Connection ~ 4650 3550
Wire Wire Line
	4650 3550 5100 3550
Connection ~ 4450 3450
Wire Wire Line
	4450 3450 5100 3450
Connection ~ 4250 3350
Wire Wire Line
	4250 3350 5100 3350
Wire Wire Line
	4450 3450 4450 3200
Wire Wire Line
	4850 3650 4850 3200
Wire Wire Line
	4000 3650 4850 3650
Wire Wire Line
	4650 3550 4650 3200
Wire Wire Line
	4000 3550 4650 3550
Wire Wire Line
	4000 3450 4450 3450
Wire Wire Line
	4250 3350 4250 3200
Wire Wire Line
	4000 3350 4250 3350
$Comp
L power:Earth #PWR?
U 1 1 5CFDAC0D
P 4200 4150
F 0 "#PWR?" H 4200 3900 50  0001 C CNN
F 1 "Earth" H 4200 4000 50  0001 C CNN
F 2 "" H 4200 4150 50  0001 C CNN
F 3 "~" H 4200 4150 50  0001 C CNN
	1    4200 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3000 5100 3000
$Comp
L power:Earth #PWR?
U 1 1 5CFDAC14
P 5100 3000
F 0 "#PWR?" H 5100 2750 50  0001 C CNN
F 1 "Earth" H 5100 2850 50  0001 C CNN
F 2 "" H 5100 3000 50  0001 C CNN
F 3 "~" H 5100 3000 50  0001 C CNN
	1    5100 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 3000 4650 3000
Connection ~ 4450 3000
Wire Wire Line
	4250 3000 4450 3000
Connection ~ 4250 3000
Connection ~ 4100 3000
Wire Wire Line
	4100 3000 4250 3000
Wire Wire Line
	4100 3250 4100 3000
Wire Wire Line
	4000 3250 4100 3250
$Comp
L Device:R_Small_US R?
U 1 1 5CFDAC22
P 4850 3100
F 0 "R?" H 4918 3100 50  0000 L CNN
F 1 "R_Small_US" H 4918 3055 50  0001 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 4850 3100 50  0001 C CNN
F 3 "~" H 4850 3100 50  0001 C CNN
	1    4850 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5CFDAC28
P 4650 3100
F 0 "R?" H 4718 3100 50  0000 L CNN
F 1 "R_Small_US" H 4718 3055 50  0001 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 4650 3100 50  0001 C CNN
F 3 "~" H 4650 3100 50  0001 C CNN
	1    4650 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5CFDAC2E
P 4450 3100
F 0 "R?" H 4518 3100 50  0000 L CNN
F 1 "R_Small_US" H 4518 3055 50  0001 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 4450 3100 50  0001 C CNN
F 3 "~" H 4450 3100 50  0001 C CNN
	1    4450 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5CFDAC34
P 4250 3100
F 0 "R?" H 4318 3100 50  0000 L CNN
F 1 "R_Small_US" H 4318 3055 50  0001 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 4250 3100 50  0001 C CNN
F 3 "~" H 4250 3100 50  0001 C CNN
	1    4250 3100
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5CFDAC3A
P 4100 3000
F 0 "#PWR?" H 4100 2850 50  0001 C CNN
F 1 "+3V3" H 4115 3173 50  0000 C CNN
F 2 "" H 4100 3000 50  0001 C CNN
F 3 "" H 4100 3000 50  0001 C CNN
	1    4100 3000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x10_Odd_Even J?
U 1 1 5CFDAC40
P 3800 3650
F 0 "J?" H 3850 4267 50  0000 C CNN
F 1 "JTAG" H 3850 4176 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x10_P2.54mm_Vertical" H 3800 3650 50  0001 C CNN
F 3 "~" H 3800 3650 50  0001 C CNN
	1    3800 3650
	-1   0    0    -1  
$EndComp
$EndSCHEMATC
