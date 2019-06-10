EESchema Schematic File Version 4
LIBS:WiFiLMR-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 6
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
L Connector_Generic:Conn_02x10_Odd_Even J?
U 1 1 5CFE681C
P 3950 3750
AR Path="/5CFE681C" Ref="J?"  Part="1" 
AR Path="/5CFB0E28/5CFE681C" Ref="J3"  Part="1" 
F 0 "J3" H 4000 4367 50  0000 C CNN
F 1 "JTAG" H 4000 4276 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x10_P2.54mm_Vertical" H 3950 3750 50  0001 C CNN
F 3 "~" H 3950 3750 50  0001 C CNN
	1    3950 3750
	-1   0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5CFE6822
P 4250 3100
AR Path="/5CFE6822" Ref="#PWR?"  Part="1" 
AR Path="/5CFB0E28/5CFE6822" Ref="#PWR0105"  Part="1" 
F 0 "#PWR0105" H 4250 2950 50  0001 C CNN
F 1 "+3V3" H 4265 3273 50  0000 C CNN
F 2 "" H 4250 3100 50  0001 C CNN
F 3 "" H 4250 3100 50  0001 C CNN
	1    4250 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5CFE6828
P 4400 3200
AR Path="/5CFE6828" Ref="R?"  Part="1" 
AR Path="/5CFB0E28/5CFE6828" Ref="R1"  Part="1" 
F 0 "R1" H 4468 3200 50  0000 L CNN
F 1 "R_Small_US" H 4468 3155 50  0001 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 4400 3200 50  0001 C CNN
F 3 "~" H 4400 3200 50  0001 C CNN
	1    4400 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5CFE682E
P 4600 3200
AR Path="/5CFE682E" Ref="R?"  Part="1" 
AR Path="/5CFB0E28/5CFE682E" Ref="R2"  Part="1" 
F 0 "R2" H 4668 3200 50  0000 L CNN
F 1 "R_Small_US" H 4668 3155 50  0001 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 4600 3200 50  0001 C CNN
F 3 "~" H 4600 3200 50  0001 C CNN
	1    4600 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5CFE6834
P 4800 3200
AR Path="/5CFE6834" Ref="R?"  Part="1" 
AR Path="/5CFB0E28/5CFE6834" Ref="R3"  Part="1" 
F 0 "R3" H 4868 3200 50  0000 L CNN
F 1 "R_Small_US" H 4868 3155 50  0001 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 4800 3200 50  0001 C CNN
F 3 "~" H 4800 3200 50  0001 C CNN
	1    4800 3200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5CFE683A
P 5000 3200
AR Path="/5CFE683A" Ref="R?"  Part="1" 
AR Path="/5CFB0E28/5CFE683A" Ref="R4"  Part="1" 
F 0 "R4" H 5068 3200 50  0000 L CNN
F 1 "R_Small_US" H 5068 3155 50  0001 L CNN
F 2 "Resistor_SMD:R_2512_6332Metric_Pad1.52x3.35mm_HandSolder" H 5000 3200 50  0001 C CNN
F 3 "~" H 5000 3200 50  0001 C CNN
	1    5000 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 3350 4250 3350
Wire Wire Line
	4250 3350 4250 3100
Wire Wire Line
	4250 3100 4400 3100
Connection ~ 4250 3100
Connection ~ 4400 3100
Wire Wire Line
	4400 3100 4600 3100
Connection ~ 4600 3100
Wire Wire Line
	4600 3100 4800 3100
$Comp
L power:Earth #PWR?
U 1 1 5CFE6848
P 5250 3100
AR Path="/5CFE6848" Ref="#PWR?"  Part="1" 
AR Path="/5CFB0E28/5CFE6848" Ref="#PWR0106"  Part="1" 
F 0 "#PWR0106" H 5250 2850 50  0001 C CNN
F 1 "Earth" H 5250 2950 50  0001 C CNN
F 2 "" H 5250 3100 50  0001 C CNN
F 3 "~" H 5250 3100 50  0001 C CNN
	1    5250 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3100 5250 3100
$Comp
L power:Earth #PWR?
U 1 1 5CFE684F
P 4350 4250
AR Path="/5CFE684F" Ref="#PWR?"  Part="1" 
AR Path="/5CFB0E28/5CFE684F" Ref="#PWR0108"  Part="1" 
F 0 "#PWR0108" H 4350 4000 50  0001 C CNN
F 1 "Earth" H 4350 4100 50  0001 C CNN
F 2 "" H 4350 4250 50  0001 C CNN
F 3 "~" H 4350 4250 50  0001 C CNN
	1    4350 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 3450 4400 3300
Wire Wire Line
	4800 3650 4800 3300
Wire Wire Line
	5000 3750 5000 3300
Wire Wire Line
	4600 3550 4600 3300
Wire Wire Line
	4150 3450 4400 3450
Wire Wire Line
	4150 3550 4600 3550
Wire Wire Line
	4150 3650 4800 3650
Wire Wire Line
	4150 3750 5000 3750
Wire Wire Line
	3650 3450 3450 3450
Wire Wire Line
	3450 3450 3450 3550
Wire Wire Line
	3650 4150 3450 4150
Wire Wire Line
	3650 4050 3450 4050
Wire Wire Line
	3650 3950 3450 3950
Connection ~ 3450 4050
Wire Wire Line
	3450 3950 3450 4050
Wire Wire Line
	3650 3850 3450 3850
Connection ~ 3450 3950
Wire Wire Line
	3450 3850 3450 3950
Wire Wire Line
	3650 3750 3450 3750
Connection ~ 3450 3850
Wire Wire Line
	3450 3750 3450 3850
Wire Wire Line
	3650 3650 3450 3650
Connection ~ 3450 3750
Wire Wire Line
	3450 3650 3450 3750
Wire Wire Line
	3650 3550 3450 3550
Connection ~ 3450 3650
Connection ~ 3450 3550
Wire Wire Line
	3450 3550 3450 3650
Wire Wire Line
	3450 4050 3450 4150
Wire Wire Line
	3450 4150 3450 4250
Connection ~ 3450 4150
Wire Wire Line
	3650 4250 3450 4250
Connection ~ 3450 4250
Wire Wire Line
	3450 4250 3450 4300
Wire Wire Line
	4150 3850 4350 3850
Wire Wire Line
	4350 3850 4350 4250
Wire Wire Line
	4400 3450 5500 3450
Connection ~ 4400 3450
Wire Wire Line
	4600 3550 5500 3550
Connection ~ 4600 3550
Wire Wire Line
	4800 3650 5500 3650
Connection ~ 4800 3650
Wire Wire Line
	5000 3750 5500 3750
Connection ~ 5000 3750
Wire Wire Line
	4150 3950 5500 3950
Wire Wire Line
	5500 4050 4150 4050
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J4
U 1 1 5D009694
P 5800 3550
F 0 "J4" H 5850 3775 50  0000 C CNN
F 1 "Conn_02x04_Odd_Even" H 5850 3776 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 5800 3550 50  0001 C CNN
F 3 "~" H 5800 3550 50  0001 C CNN
	1    5800 3550
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J5
U 1 1 5D00B4A0
P 5800 3950
F 0 "J5" H 5850 4075 50  0000 C CNN
F 1 "Conn_02x02_Odd_Even" H 5850 4076 50  0001 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x02_P2.54mm_Vertical" H 5800 3950 50  0001 C CNN
F 3 "~" H 5800 3950 50  0001 C CNN
	1    5800 3950
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6000 3450 6300 3450
Wire Wire Line
	6300 3550 6000 3550
Wire Wire Line
	6000 3650 6300 3650
Wire Wire Line
	6300 3750 6000 3750
Wire Wire Line
	6000 3950 6300 3950
Wire Wire Line
	6300 4050 6000 4050
$Comp
L power:Earth #PWR?
U 1 1 5D019288
P 3450 4300
AR Path="/5D019288" Ref="#PWR?"  Part="1" 
AR Path="/5CFB0E28/5D019288" Ref="#PWR0101"  Part="1" 
F 0 "#PWR0101" H 3450 4050 50  0001 C CNN
F 1 "Earth" H 3450 4150 50  0001 C CNN
F 2 "" H 3450 4300 50  0001 C CNN
F 3 "~" H 3450 4300 50  0001 C CNN
	1    3450 4300
	1    0    0    -1  
$EndComp
NoConn ~ 3650 3350
NoConn ~ 4150 4150
NoConn ~ 4150 4250
Text GLabel 6300 3450 2    50   BiDi ~ 0
JTAG_TRST|SPI1_MISO|TIM3_CH1
Text GLabel 6300 3550 2    50   BiDi ~ 0
JTAG_TDI|SPI1_SS|I2S3_WS
Text GLabel 6300 3650 2    50   BiDi ~ 0
JTAG_TMS
Text GLabel 6300 3750 2    50   BiDi ~ 0
JTAG_TCK
Text GLabel 6300 3950 2    50   BiDi ~ 0
JTAG_TDO|SPI1_SCK|I2S3_SCK
Text GLabel 6300 4050 2    50   BiDi ~ 0
RST
$EndSCHEMATC
