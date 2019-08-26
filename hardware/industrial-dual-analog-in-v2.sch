EESchema Schematic File Version 4
LIBS:industrial-dual-analog-in-v2-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Industrial Dual Analog In"
Date "2019-08-26"
Rev "2.1"
Comp "Tinkerforge GmbH"
Comment1 "Licensed under CERN OHL v.1.1"
Comment2 "Copyright (©) 2018, B.Nordmeyer <bastian@tinkerforge.com>"
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 7550 6500 0    60   ~ 0
Copyright Tinkerforge GmbH 2019.\nThis documentation describes Open Hardware and is licensed under the\nCERN OHL v. 1.1.\nYou may redistribute and modify this documentation under the terms of the\nCERN OHL v.1.1. (http://ohwr.org/cernohl). This documentation is distributed\nWITHOUT ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING OF\nMERCHANTABILITY, SATISFACTORY QUALITY AND FITNESS FOR A\nPARTICULAR PURPOSE. Please see the CERN OHL v.1.1 for applicable\nconditions\n
$Comp
L industrial-dual-analog-in-v2-rescue:DRILL U6
U 1 1 5006691C
P 10650 7000
F 0 "U6" H 10700 7050 60  0001 C CNN
F 1 "DRILL" H 10650 7000 60  0000 C CNN
F 2 "kicad-libraries:DRILL_NP" H 10650 7000 60  0001 C CNN
F 3 "" H 10650 7000 60  0001 C CNN
	1    10650 7000
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DRILL U5
U 1 1 5006691A
P 10650 6750
F 0 "U5" H 10700 6800 60  0001 C CNN
F 1 "DRILL" H 10650 6750 60  0000 C CNN
F 2 "kicad-libraries:DRILL_NP" H 10650 6750 60  0001 C CNN
F 3 "" H 10650 6750 60  0001 C CNN
	1    10650 6750
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DRILL U7
U 1 1 50066918
P 11000 6750
F 0 "U7" H 11050 6800 60  0001 C CNN
F 1 "DRILL" H 11000 6750 60  0000 C CNN
F 2 "kicad-libraries:DRILL_NP" H 11000 6750 60  0001 C CNN
F 3 "" H 11000 6750 60  0001 C CNN
	1    11000 6750
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DRILL U8
U 1 1 50066905
P 11000 7000
F 0 "U8" H 11050 7050 60  0001 C CNN
F 1 "DRILL" H 11000 7000 60  0000 C CNN
F 2 "kicad-libraries:DRILL_NP" H 11000 7000 60  0001 C CNN
F 3 "" H 11000 7000 60  0001 C CNN
	1    11000 7000
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:3V3 #PWR01
U 1 1 5004F895
P 1850 650
F 0 "#PWR01" H 1850 750 40  0001 C CNN
F 1 "3V3" H 1850 775 40  0000 C CNN
F 2 "" H 1850 650 60  0001 C CNN
F 3 "" H 1850 650 60  0001 C CNN
	1    1850 650 
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:+5V #PWR02
U 1 1 5326F89A
P 1250 650
F 0 "#PWR02" H 1250 740 20  0001 C CNN
F 1 "+5V" H 1250 740 30  0000 C CNN
F 2 "" H 1250 650 60  0000 C CNN
F 3 "" H 1250 650 60  0000 C CNN
	1    1250 650 
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:MCP3911 U4
U 1 1 532708B4
P 5100 6400
F 0 "U4" H 4700 6950 60  0000 C CNN
F 1 "MCP3911" H 4900 5850 60  0000 C CNN
F 2 "kicad-libraries:SSOP20-53" H 4650 7000 60  0001 C CNN
F 3 "" H 4650 7000 60  0000 C CNN
	1    5100 6400
	-1   0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR03
U 1 1 532708CD
P 5900 7500
F 0 "#PWR03" H 5900 7500 40  0001 C CNN
F 1 "AGND" H 5900 7430 50  0000 C CNN
F 2 "" H 5900 7500 60  0000 C CNN
F 3 "" H 5900 7500 60  0000 C CNN
	1    5900 7500
	1    0    0    -1  
$EndComp
NoConn ~ 4500 6650
NoConn ~ 4500 6750
$Comp
L industrial-dual-analog-in-v2-rescue:C C14
U 1 1 53270C1C
P 6200 7150
F 0 "C14" H 6250 7250 50  0000 L CNN
F 1 "100nF" H 6250 7050 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 6200 7150 60  0001 C CNN
F 3 "" H 6200 7150 60  0001 C CNN
	1    6200 7150
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR04
U 1 1 53270C54
P 6200 7500
F 0 "#PWR04" H 6200 7500 40  0001 C CNN
F 1 "AGND" H 6200 7430 50  0000 C CNN
F 2 "" H 6200 7500 60  0000 C CNN
F 3 "" H 6200 7500 60  0000 C CNN
	1    6200 7500
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR05
U 1 1 53270DD4
P 5700 7500
F 0 "#PWR05" H 5700 7500 40  0001 C CNN
F 1 "AGND" H 5700 7430 50  0000 C CNN
F 2 "" H 5700 7500 60  0000 C CNN
F 3 "" H 5700 7500 60  0000 C CNN
	1    5700 7500
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C16
U 1 1 53270F71
P 6900 5450
F 0 "C16" H 6950 5550 50  0000 L CNN
F 1 "10µF" H 6950 5350 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 6900 5450 60  0001 C CNN
F 3 "" H 6900 5450 60  0001 C CNN
	1    6900 5450
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C15
U 1 1 53270F81
P 6650 5450
F 0 "C15" H 6700 5550 50  0000 L CNN
F 1 "100nF" H 6700 5350 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 6650 5450 60  0001 C CNN
F 3 "" H 6650 5450 60  0001 C CNN
	1    6650 5450
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C13
U 1 1 53270F87
P 6150 5450
F 0 "C13" H 6200 5550 50  0000 L CNN
F 1 "10µF" H 6200 5350 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 6150 5450 60  0001 C CNN
F 3 "" H 6150 5450 60  0001 C CNN
	1    6150 5450
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C12
U 1 1 53270F8D
P 5900 5450
F 0 "C12" H 5950 5550 50  0000 L CNN
F 1 "100nF" H 5950 5350 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 5900 5450 60  0001 C CNN
F 3 "" H 5900 5450 60  0001 C CNN
	1    5900 5450
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR06
U 1 1 532710BD
P 6650 5700
F 0 "#PWR06" H 6650 5700 40  0001 C CNN
F 1 "AGND" H 6650 5630 50  0000 C CNN
F 2 "" H 6650 5700 60  0000 C CNN
F 3 "" H 6650 5700 60  0000 C CNN
	1    6650 5700
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR07
U 1 1 532710C3
P 6900 5700
F 0 "#PWR07" H 6900 5700 40  0001 C CNN
F 1 "AGND" H 6900 5630 50  0000 C CNN
F 2 "" H 6900 5700 60  0000 C CNN
F 3 "" H 6900 5700 60  0000 C CNN
	1    6900 5700
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R7
U 1 1 53271205
P 5900 4950
F 0 "R7" V 5980 4950 50  0000 C CNN
F 1 "10" V 5900 4950 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 5900 4950 60  0001 C CNN
F 3 "" H 5900 4950 60  0000 C CNN
	1    5900 4950
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R12
U 1 1 5327121E
P 6650 4950
F 0 "R12" V 6730 4950 50  0000 C CNN
F 1 "10" V 6650 4950 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 6650 4950 60  0001 C CNN
F 3 "" H 6650 4950 60  0000 C CNN
	1    6650 4950
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR08
U 1 1 53271582
P 5900 5700
F 0 "#PWR08" H 5900 5700 40  0001 C CNN
F 1 "DGND" H 5900 5630 40  0000 C CNN
F 2 "" H 5900 5700 60  0000 C CNN
F 3 "" H 5900 5700 60  0000 C CNN
	1    5900 5700
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR09
U 1 1 532715A3
P 6150 5700
F 0 "#PWR09" H 6150 5700 40  0001 C CNN
F 1 "DGND" H 6150 5630 40  0000 C CNN
F 2 "" H 6150 5700 60  0000 C CNN
F 3 "" H 6150 5700 60  0000 C CNN
	1    6150 5700
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR010
U 1 1 532715BB
P 4500 7500
F 0 "#PWR010" H 4500 7500 40  0001 C CNN
F 1 "DGND" H 4500 7430 40  0000 C CNN
F 2 "" H 4500 7500 60  0000 C CNN
F 3 "" H 4500 7500 60  0000 C CNN
	1    4500 7500
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:TLV272 U1
U 3 1 53275DE9
P 1400 6850
F 0 "U1" H 1350 7050 60  0000 L CNN
F 1 "LMV342IDRG4" H 1350 6600 60  0000 L CNN
F 2 "kicad-libraries:SOIC8" H 1400 6850 60  0001 C CNN
F 3 "" H 1400 6850 60  0000 C CNN
	3    1400 6850
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:TLV272 U1
U 1 1 53275DFD
P 5950 3500
F 0 "U1" H 5900 3700 60  0000 L CNN
F 1 "LMV342IDRG4" H 5900 3250 60  0000 L CNN
F 2 "kicad-libraries:SOIC8" H 5950 3500 60  0001 C CNN
F 3 "" H 5950 3500 60  0000 C CNN
	1    5950 3500
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C18
U 1 1 53276055
P 7300 1400
F 0 "C18" H 7350 1300 50  0000 L CNN
F 1 "150pF" H 7050 1300 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 7300 1400 60  0001 C CNN
F 3 "" H 7300 1400 60  0001 C CNN
	1    7300 1400
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R14
U 1 1 53276065
P 6750 1500
F 0 "R14" V 6830 1500 50  0000 C CNN
F 1 "280k/10ppm" V 6750 1500 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 6750 1500 60  0001 C CNN
F 3 "" H 6750 1500 60  0000 C CNN
	1    6750 1500
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R13
U 1 1 5327606B
P 6750 1300
F 0 "R13" V 6830 1300 50  0000 C CNN
F 1 "280k/10ppm" V 6750 1300 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 6750 1300 60  0001 C CNN
F 3 "" H 6750 1300 60  0000 C CNN
	1    6750 1300
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R10
U 1 1 53276071
P 6450 1850
F 0 "R10" V 6530 1850 50  0000 C CNN
F 1 "4k7/10ppm" V 6450 1850 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 6450 1850 60  0001 C CNN
F 3 "" H 6450 1850 60  0000 C CNN
	1    6450 1850
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R8
U 1 1 53276077
P 5950 1000
F 0 "R8" V 6030 1000 50  0000 C CNN
F 1 "4k7/10ppm" V 5950 1000 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 5950 1000 60  0001 C CNN
F 3 "" H 5950 1000 60  0000 C CNN
	1    5950 1000
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C17
U 1 1 532762D5
P 7300 950
F 0 "C17" H 7350 850 50  0000 L CNN
F 1 "15pF" H 7050 850 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 7300 950 60  0001 C CNN
F 3 "" H 7300 950 60  0001 C CNN
	1    7300 950 
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C19
U 1 1 532762DB
P 7300 1850
F 0 "C19" H 7350 1750 50  0000 L CNN
F 1 "15pF" H 7050 1750 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 7300 1850 60  0001 C CNN
F 3 "" H 7300 1850 60  0001 C CNN
	1    7300 1850
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR011
U 1 1 5327653A
P 7300 2500
F 0 "#PWR011" H 7300 2500 40  0001 C CNN
F 1 "AGND" H 7300 2430 50  0000 C CNN
F 2 "" H 7300 2500 60  0000 C CNN
F 3 "" H 7300 2500 60  0000 C CNN
	1    7300 2500
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR012
U 1 1 53276540
P 7450 650
F 0 "#PWR012" H 7450 650 40  0001 C CNN
F 1 "AGND" H 7450 580 50  0000 C CNN
F 2 "" H 7450 650 60  0000 C CNN
F 3 "" H 7450 650 60  0000 C CNN
	1    7450 650 
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R21
U 1 1 53276639
P 8500 1100
F 0 "R21" V 8580 1100 50  0000 C CNN
F 1 "100k" V 8500 1100 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 8500 1100 60  0001 C CNN
F 3 "" H 8500 1100 60  0000 C CNN
	1    8500 1100
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R22
U 1 1 5327664B
P 8500 1700
F 0 "R22" V 8580 1700 50  0000 C CNN
F 1 "100k" V 8500 1700 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 8500 1700 60  0001 C CNN
F 3 "" H 8500 1700 60  0000 C CNN
	1    8500 1700
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR013
U 1 1 5327665B
P 8650 1450
F 0 "#PWR013" H 8650 1450 40  0001 C CNN
F 1 "AGND" H 8650 1380 50  0000 C CNN
F 2 "" H 8650 1450 60  0000 C CNN
F 3 "" H 8650 1450 60  0000 C CNN
	1    8650 1450
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R17
U 1 1 53277BB6
P 7900 850
F 0 "R17" V 7980 850 50  0000 C CNN
F 1 "10" V 7900 850 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 7900 850 60  0001 C CNN
F 3 "" H 7900 850 60  0000 C CNN
	1    7900 850 
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R18
U 1 1 53277BD2
P 7900 1950
F 0 "R18" V 7980 1950 50  0000 C CNN
F 1 "10" V 7900 1950 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 7900 1950 60  0001 C CNN
F 3 "" H 7900 1950 60  0000 C CNN
	1    7900 1950
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R5
U 1 1 53277BD8
P 5150 1400
F 0 "R5" V 5230 1400 50  0000 C CNN
F 1 "68.1" V 5150 1400 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 5150 1400 60  0001 C CNN
F 3 "" H 5150 1400 60  0000 C CNN
	1    5150 1400
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C10
U 1 1 53277BDE
P 4900 1650
F 0 "C10" H 4950 1550 50  0000 L CNN
F 1 "1nF" H 4650 1550 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 4900 1650 60  0001 C CNN
F 3 "" H 4900 1650 60  0001 C CNN
	1    4900 1650
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR014
U 1 1 53277BFC
P 6450 2500
F 0 "#PWR014" H 6450 2500 40  0001 C CNN
F 1 "AGND" H 6450 2430 50  0000 C CNN
F 2 "" H 6450 2500 60  0000 C CNN
F 3 "" H 6450 2500 60  0000 C CNN
	1    6450 2500
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR015
U 1 1 53277C02
P 4900 2500
F 0 "#PWR015" H 4900 2500 40  0001 C CNN
F 1 "AGND" H 4900 2430 50  0000 C CNN
F 2 "" H 4900 2500 60  0000 C CNN
F 3 "" H 4900 2500 60  0000 C CNN
	1    4900 2500
	1    0    0    -1  
$EndComp
Text GLabel 4650 1400 0    47   Output ~ 0
ADC0
$Comp
L industrial-dual-analog-in-v2-rescue:TLV272 U1
U 2 1 53278034
P 5950 1400
F 0 "U1" H 5900 1600 60  0000 L CNN
F 1 "LMV342IDRG4" H 5900 1150 60  0000 L CNN
F 2 "kicad-libraries:SOIC8" H 5950 1400 60  0001 C CNN
F 3 "" H 5950 1400 60  0000 C CNN
	2    5950 1400
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C21
U 1 1 5327803A
P 7300 3500
F 0 "C21" H 7350 3400 50  0000 L CNN
F 1 "150pF" H 7050 3400 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 7300 3500 60  0001 C CNN
F 3 "" H 7300 3500 60  0001 C CNN
	1    7300 3500
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R16
U 1 1 53278040
P 6750 3600
F 0 "R16" V 6830 3600 50  0000 C CNN
F 1 "280k/10ppm" V 6750 3600 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 6750 3600 60  0001 C CNN
F 3 "" H 6750 3600 60  0000 C CNN
	1    6750 3600
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R15
U 1 1 53278046
P 6750 3400
F 0 "R15" V 6830 3400 50  0000 C CNN
F 1 "280k/10ppm" V 6750 3400 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 6750 3400 60  0001 C CNN
F 3 "" H 6750 3400 60  0000 C CNN
	1    6750 3400
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R11
U 1 1 5327804C
P 6450 3950
F 0 "R11" V 6530 3950 50  0000 C CNN
F 1 "4k7/10ppm" V 6450 3950 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 6450 3950 60  0001 C CNN
F 3 "" H 6450 3950 60  0000 C CNN
	1    6450 3950
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R9
U 1 1 53278052
P 5950 3100
F 0 "R9" V 6030 3100 50  0000 C CNN
F 1 "4k7/10ppm" V 5950 3100 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 5950 3100 60  0001 C CNN
F 3 "" H 5950 3100 60  0000 C CNN
	1    5950 3100
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C20
U 1 1 5327805F
P 7300 3050
F 0 "C20" H 7350 2950 50  0000 L CNN
F 1 "15pF" H 7050 2950 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 7300 3050 60  0001 C CNN
F 3 "" H 7300 3050 60  0001 C CNN
	1    7300 3050
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C22
U 1 1 53278065
P 7300 3950
F 0 "C22" H 7350 3850 50  0000 L CNN
F 1 "15pF" H 7050 3850 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 7300 3950 60  0001 C CNN
F 3 "" H 7300 3950 60  0001 C CNN
	1    7300 3950
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR016
U 1 1 53278077
P 7300 4600
F 0 "#PWR016" H 7300 4600 40  0001 C CNN
F 1 "AGND" H 7300 4530 50  0000 C CNN
F 2 "" H 7300 4600 60  0000 C CNN
F 3 "" H 7300 4600 60  0000 C CNN
	1    7300 4600
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR017
U 1 1 5327807D
P 7450 2750
F 0 "#PWR017" H 7450 2750 40  0001 C CNN
F 1 "AGND" H 7450 2680 50  0000 C CNN
F 2 "" H 7450 2750 60  0000 C CNN
F 3 "" H 7450 2750 60  0000 C CNN
	1    7450 2750
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R23
U 1 1 53278087
P 8500 3200
F 0 "R23" V 8580 3200 50  0000 C CNN
F 1 "100k" V 8500 3200 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 8500 3200 60  0001 C CNN
F 3 "" H 8500 3200 60  0000 C CNN
	1    8500 3200
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R24
U 1 1 5327808D
P 8500 3800
F 0 "R24" V 8580 3800 50  0000 C CNN
F 1 "100k" V 8500 3800 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 8500 3800 60  0001 C CNN
F 3 "" H 8500 3800 60  0000 C CNN
	1    8500 3800
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR018
U 1 1 53278093
P 8650 3550
F 0 "#PWR018" H 8650 3550 40  0001 C CNN
F 1 "AGND" H 8650 3480 50  0000 C CNN
F 2 "" H 8650 3550 60  0000 C CNN
F 3 "" H 8650 3550 60  0000 C CNN
	1    8650 3550
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R19
U 1 1 532780F5
P 7900 2950
F 0 "R19" V 7980 2950 50  0000 C CNN
F 1 "10" V 7900 2950 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 7900 2950 60  0001 C CNN
F 3 "" H 7900 2950 60  0000 C CNN
	1    7900 2950
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R20
U 1 1 532780FB
P 7900 4050
F 0 "R20" V 7980 4050 50  0000 C CNN
F 1 "10" V 7900 4050 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 7900 4050 60  0001 C CNN
F 3 "" H 7900 4050 60  0000 C CNN
	1    7900 4050
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R6
U 1 1 53278101
P 5150 3500
F 0 "R6" V 5230 3500 50  0000 C CNN
F 1 "68.1" V 5150 3500 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 5150 3500 60  0001 C CNN
F 3 "" H 5150 3500 60  0000 C CNN
	1    5150 3500
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C11
U 1 1 53278107
P 4900 3750
F 0 "C11" H 4950 3650 50  0000 L CNN
F 1 "1nF" H 4650 3650 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 4900 3750 60  0001 C CNN
F 3 "" H 4900 3750 60  0001 C CNN
	1    4900 3750
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR019
U 1 1 5327810D
P 6450 4600
F 0 "#PWR019" H 6450 4600 40  0001 C CNN
F 1 "AGND" H 6450 4530 50  0000 C CNN
F 2 "" H 6450 4600 60  0000 C CNN
F 3 "" H 6450 4600 60  0000 C CNN
	1    6450 4600
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR020
U 1 1 53278113
P 4900 4600
F 0 "#PWR020" H 4900 4600 40  0001 C CNN
F 1 "AGND" H 4900 4530 50  0000 C CNN
F 2 "" H 4900 4600 60  0000 C CNN
F 3 "" H 4900 4600 60  0000 C CNN
	1    4900 4600
	1    0    0    -1  
$EndComp
Text GLabel 4650 3500 0    47   Output ~ 0
ADC1
Text GLabel 6350 6550 2    47   Input ~ 0
ADC0
Text GLabel 6350 6250 2    47   Input ~ 0
ADC1
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR021
U 1 1 5327868D
P 6250 6600
F 0 "#PWR021" H 6250 6600 40  0001 C CNN
F 1 "AGND" H 6250 6530 50  0000 C CNN
F 2 "" H 6250 6600 60  0000 C CNN
F 3 "" H 6250 6600 60  0000 C CNN
	1    6250 6600
	1    0    0    -1  
$EndComp
Text Notes 10000 1550 0    60   ~ 0
max +-35V
$Comp
L industrial-dual-analog-in-v2-rescue:C C1
U 1 1 53281CCC
P 1050 6600
F 0 "C1" H 950 6500 50  0000 L CNN
F 1 "100nF" H 800 6700 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 1050 6600 60  0001 C CNN
F 3 "" H 1050 6600 60  0001 C CNN
	1    1050 6600
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C2
U 1 1 53281CD2
P 1050 7100
F 0 "C2" H 950 7000 50  0000 L CNN
F 1 "100nF" H 800 7200 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 1050 7100 60  0001 C CNN
F 3 "" H 1050 7100 60  0001 C CNN
	1    1050 7100
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR022
U 1 1 53281CD8
P 850 6950
F 0 "#PWR022" H 850 6950 40  0001 C CNN
F 1 "AGND" H 850 6880 50  0000 C CNN
F 2 "" H 850 6950 60  0000 C CNN
F 3 "" H 850 6950 60  0000 C CNN
	1    850  6950
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:INDUCT FB1
U 1 1 532826FE
P 2450 6600
F 0 "FB1" V 2550 6350 60  0000 C CNN
F 1 "FILTER" V 2550 6600 60  0000 C CNN
F 2 "kicad-libraries:C0603F" H 2450 6600 60  0001 C CNN
F 3 "" H 2450 6600 60  0000 C CNN
	1    2450 6600
	0    1    1    0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:INDUCT FB2
U 1 1 5327183F
P 2450 6850
F 0 "FB2" V 2550 6600 60  0000 C CNN
F 1 "FILTER" V 2550 6850 60  0000 C CNN
F 2 "kicad-libraries:C0603F" H 2450 6850 60  0001 C CNN
F 3 "" H 2450 6850 60  0000 C CNN
	1    2450 6850
	0    1    1    0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R1
U 1 1 53271695
P 2500 7400
F 0 "R1" V 2580 7400 50  0000 C CNN
F 1 "0" V 2500 7400 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 2500 7400 60  0001 C CNN
F 3 "" H 2500 7400 60  0000 C CNN
	1    2500 7400
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR023
U 1 1 5327168F
P 2250 7600
F 0 "#PWR023" H 2250 7600 40  0001 C CNN
F 1 "DGND" H 2250 7530 40  0000 C CNN
F 2 "" H 2250 7600 60  0000 C CNN
F 3 "" H 2250 7600 60  0000 C CNN
	1    2250 7600
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R R2
U 1 1 532715C1
P 3500 6600
F 0 "R2" V 3580 6600 50  0000 C CNN
F 1 "1M" V 3500 6600 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 3500 6600 60  0001 C CNN
F 3 "" H 3500 6600 60  0000 C CNN
	1    3500 6600
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR024
U 1 1 532715AF
P 3800 7500
F 0 "#PWR024" H 3800 7500 40  0001 C CNN
F 1 "DGND" H 3800 7430 40  0000 C CNN
F 2 "" H 3800 7500 60  0000 C CNN
F 3 "" H 3800 7500 60  0000 C CNN
	1    3800 7500
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR025
U 1 1 532715A9
P 3200 7500
F 0 "#PWR025" H 3200 7500 40  0001 C CNN
F 1 "DGND" H 3200 7430 40  0000 C CNN
F 2 "" H 3200 7500 60  0000 C CNN
F 3 "" H 3200 7500 60  0000 C CNN
	1    3200 7500
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C9
U 1 1 532709EF
P 3800 7200
F 0 "C9" H 3850 7300 50  0000 L CNN
F 1 "18pF" H 3600 7300 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 3800 7200 60  0001 C CNN
F 3 "" H 3800 7200 60  0001 C CNN
	1    3800 7200
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C8
U 1 1 532709E9
P 3200 7200
F 0 "C8" H 3250 7300 50  0000 L CNN
F 1 "18pF" H 3000 7300 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 3200 7200 60  0001 C CNN
F 3 "" H 3200 7200 60  0001 C CNN
	1    3200 7200
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR026
U 1 1 5326FF29
P 2750 7600
F 0 "#PWR026" H 2750 7600 40  0001 C CNN
F 1 "AGND" H 2750 7530 50  0000 C CNN
F 2 "" H 2750 7600 60  0000 C CNN
F 3 "" H 2750 7600 60  0000 C CNN
	1    2750 7600
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:+3.3VADC #PWR027
U 1 1 54297D5A
P 2850 6600
F 0 "#PWR027" H 2850 6720 20  0001 C CNN
F 1 "+3.3VADC" H 2850 6690 30  0000 C CNN
F 2 "" H 2850 6600 60  0000 C CNN
F 3 "" H 2850 6600 60  0000 C CNN
	1    2850 6600
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:+3.3VADC #PWR028
U 1 1 54297FAE
P 6650 4650
F 0 "#PWR028" H 6650 4770 20  0001 C CNN
F 1 "+3.3VADC" H 6650 4740 30  0000 C CNN
F 2 "" H 6650 4650 60  0000 C CNN
F 3 "" H 6650 4650 60  0000 C CNN
	1    6650 4650
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:+3.3VP #PWR029
U 1 1 542986C7
P 5900 4650
F 0 "#PWR029" H 5950 4680 20  0001 C CNN
F 1 "+3.3VP" H 5900 4740 30  0000 C CNN
F 2 "" H 5900 4650 60  0000 C CNN
F 3 "" H 5900 4650 60  0000 C CNN
	1    5900 4650
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:+3.3VP #PWR030
U 1 1 54298919
P 2850 6850
F 0 "#PWR030" H 2900 6880 20  0001 C CNN
F 1 "+3.3VP" H 2850 6940 30  0000 C CNN
F 2 "" H 2850 6850 60  0000 C CNN
F 3 "" H 2850 6850 60  0000 C CNN
	1    2850 6850
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:+3.3VADC #PWR031
U 1 1 54299760
P 1400 6300
F 0 "#PWR031" H 1400 6420 20  0001 C CNN
F 1 "+3.3VADC" H 1400 6390 30  0000 C CNN
F 2 "" H 1400 6300 60  0000 C CNN
F 3 "" H 1400 6300 60  0000 C CNN
	1    1400 6300
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:3V3 #PWR032
U 1 1 5429A136
P 2100 6550
F 0 "#PWR032" H 2100 6650 40  0001 C CNN
F 1 "3V3" H 2100 6675 40  0000 C CNN
F 2 "" H 2100 6550 60  0001 C CNN
F 3 "" H 2100 6550 60  0001 C CNN
	1    2100 6550
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:-VAA #PWR033
U 1 1 5429ADF3
P 1400 7400
F 0 "#PWR033" H 1400 7500 20  0001 C CNN
F 1 "-VAA" H 1400 7500 30  0000 C CNN
F 2 "" H 1400 7400 60  0000 C CNN
F 3 "" H 1400 7400 60  0000 C CNN
	1    1400 7400
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:-VAA #PWR034
U 1 1 5429B005
P 2750 5550
F 0 "#PWR034" H 2750 5650 20  0001 C CNN
F 1 "-VAA" H 2750 5650 30  0000 C CNN
F 2 "" H 2750 5550 60  0000 C CNN
F 3 "" H 2750 5550 60  0000 C CNN
	1    2750 5550
	0    1    1    0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:LM2664 U2
U 1 1 5429CE3A
P 1850 5400
F 0 "U2" H 1600 5650 60  0000 C CNN
F 1 "LM2664" H 1850 5150 60  0000 C CNN
F 2 "kicad-libraries:SOT23-6" H 1100 4400 60  0001 C CNN
F 3 "" H 1100 4400 60  0000 C CNN
	1    1850 5400
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C5
U 1 1 542A0985
P 2550 5250
F 0 "C5" V 2600 5100 50  0000 L CNN
F 1 "3.3µF" V 2450 4950 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 2550 5250 60  0001 C CNN
F 3 "" H 2550 5250 60  0001 C CNN
	1    2550 5250
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C3
U 1 1 542A12AD
P 1000 5450
F 0 "C3" V 1050 5300 50  0000 L CNN
F 1 "3.3µF" V 900 5150 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 1000 5450 60  0001 C CNN
F 3 "" H 1000 5450 60  0001 C CNN
	1    1000 5450
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C4
U 1 1 542A23C2
P 2350 5750
F 0 "C4" H 2200 5850 50  0000 L CNN
F 1 "3.3µF" H 2100 5650 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 2350 5750 60  0001 C CNN
F 3 "" H 2350 5750 60  0001 C CNN
	1    2350 5750
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C6
U 1 1 542A2ABC
P 2650 5750
F 0 "C6" H 2550 5650 50  0000 L CNN
F 1 "100nF" H 2400 5850 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 2650 5750 60  0001 C CNN
F 3 "" H 2650 5750 60  0001 C CNN
	1    2650 5750
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:CONN_8 P3
U 1 1 5429473E
P 10500 2700
F 0 "P3" V 10450 2700 60  0000 C CNN
F 1 "CONN_8" V 10550 2700 60  0000 C CNN
F 2 "kicad-libraries:OQ_8P" H 10500 2700 60  0001 C CNN
F 3 "" H 10500 2700 60  0000 C CNN
	1    10500 2700
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:CONN_1 P2
U 1 1 542949F5
P 1600 7350
F 0 "P2" H 1680 7350 40  0000 L CNN
F 1 "CONN_1" H 1600 7405 30  0001 C CNN
F 2 "kicad-libraries:PINTST" H 1600 7350 60  0001 C CNN
F 3 "" H 1600 7350 60  0000 C CNN
	1    1600 7350
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:3V3 #PWR035
U 1 1 54295E66
P 9550 1900
F 0 "#PWR035" H 9550 2000 40  0001 C CNN
F 1 "3V3" H 9550 2025 40  0000 C CNN
F 2 "" H 9550 1900 60  0001 C CNN
F 3 "" H 9550 1900 60  0001 C CNN
	1    9550 1900
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:+5V #PWR036
U 1 1 5429621B
P 9250 1900
F 0 "#PWR036" H 9250 1990 20  0001 C CNN
F 1 "+5V" H 9250 1990 30  0000 C CNN
F 2 "" H 9250 1900 60  0000 C CNN
F 3 "" H 9250 1900 60  0000 C CNN
	1    9250 1900
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR037
U 1 1 54296B22
P 10050 3250
F 0 "#PWR037" H 10050 3250 40  0001 C CNN
F 1 "AGND" H 10050 3180 50  0000 C CNN
F 2 "" H 10050 3250 60  0000 C CNN
F 3 "" H 10050 3250 60  0000 C CNN
	1    10050 3250
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR038
U 1 1 542ADCCA
P 2650 6050
F 0 "#PWR038" H 2650 6050 40  0001 C CNN
F 1 "AGND" H 2650 5980 50  0000 C CNN
F 2 "" H 2650 6050 60  0000 C CNN
F 3 "" H 2650 6050 60  0000 C CNN
	1    2650 6050
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR039
U 1 1 542ADF4B
P 2350 6050
F 0 "#PWR039" H 2350 6050 40  0001 C CNN
F 1 "AGND" H 2350 5980 50  0000 C CNN
F 2 "" H 2350 6050 60  0000 C CNN
F 3 "" H 2350 6050 60  0000 C CNN
	1    2350 6050
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR040
U 1 1 542AE0D0
P 1000 5700
F 0 "#PWR040" H 1000 5700 40  0001 C CNN
F 1 "AGND" H 1000 5630 50  0000 C CNN
F 2 "" H 1000 5700 60  0000 C CNN
F 3 "" H 1000 5700 60  0000 C CNN
	1    1000 5700
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:+3.3VADC #PWR041
U 1 1 542AE7FE
P 1000 5050
F 0 "#PWR041" H 1000 5170 20  0001 C CNN
F 1 "+3.3VADC" H 1000 5140 30  0000 C CNN
F 2 "" H 1000 5050 60  0000 C CNN
F 3 "" H 1000 5050 60  0000 C CNN
	1    1000 5050
	1    0    0    -1  
$EndComp
Text Notes 8100 5100 0    60   ~ 0
Ua = U_-*(R14+R8)/R14*R10/(R15+R10)-U_+*R8/R14
Text Notes 8100 4850 0    60   ~ 0
Range +-35.74V (0.6V), +-47.65V (0.8V)
$Comp
L industrial-dual-analog-in-v2-rescue:R R3
U 1 1 54ECA249
P 3650 5750
F 0 "R3" V 3730 5750 50  0000 C CNN
F 1 "100k" V 3650 5750 50  0000 C CNN
F 2 "kicad-libraries:R0603F" H 3650 5750 60  0001 C CNN
F 3 "" H 3650 5750 60  0000 C CNN
	1    3650 5750
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:+3.3VP #PWR042
U 1 1 54ECA4E0
P 3650 5450
F 0 "#PWR042" H 3700 5480 20  0001 C CNN
F 1 "+3.3VP" H 3650 5540 30  0000 C CNN
F 2 "" H 3650 5450 60  0000 C CNN
F 3 "" H 3650 5450 60  0000 C CNN
	1    3650 5450
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:FUSE F2
U 1 1 551D880D
P 9550 2300
F 0 "F2" H 9650 2350 40  0000 C CNN
F 1 "OZCJ0035FF2G" H 9450 2250 40  0000 C CNN
F 2 "kicad-libraries:F1206" H 9550 2300 60  0001 C CNN
F 3 "" H 9550 2300 60  0000 C CNN
	1    9550 2300
	0    1    1    0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:TVS D2
U 1 1 551DE4F8
P 9550 3300
F 0 "D2" H 9500 3400 40  0000 C CNN
F 1 "CDSOD323-T03SC" H 9550 3200 40  0000 C CNN
F 2 "kicad-libraries:SOD-323" H 9550 3300 60  0001 C CNN
F 3 "" H 9550 3300 60  0000 C CNN
	1    9550 3300
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:TVS D1
U 1 1 551DEDDC
P 9250 3300
F 0 "D1" H 9200 3400 40  0000 C CNN
F 1 "CDSOD323-T05SC" H 9250 3200 40  0000 C CNN
F 2 "kicad-libraries:SOD-323" H 9250 3300 60  0001 C CNN
F 3 "" H 9250 3300 60  0000 C CNN
	1    9250 3300
	0    -1   -1   0   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR043
U 1 1 551DF5C9
P 9550 3600
F 0 "#PWR043" H 9550 3600 40  0001 C CNN
F 1 "AGND" H 9550 3530 50  0000 C CNN
F 2 "" H 9550 3600 60  0000 C CNN
F 3 "" H 9550 3600 60  0000 C CNN
	1    9550 3600
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:AGND #PWR044
U 1 1 551DF6CD
P 9250 3600
F 0 "#PWR044" H 9250 3600 40  0001 C CNN
F 1 "AGND" H 9250 3530 50  0000 C CNN
F 2 "" H 9250 3600 60  0000 C CNN
F 3 "" H 9250 3600 60  0000 C CNN
	1    9250 3600
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:FUSE F1
U 1 1 551DFCDA
P 9250 2300
F 0 "F1" H 9350 2350 40  0000 C CNN
F 1 "OZCJ0035FF2G" H 9150 2250 40  0000 C CNN
F 2 "kicad-libraries:F1206" H 9250 2300 60  0001 C CNN
F 3 "" H 9250 2300 60  0000 C CNN
	1    9250 2300
	0    1    1    0   
$EndComp
Text Notes 8100 5250 0    60   ~ 0
R14=R15 und R8=R10 -> Ua = R8/R14*(U_+ - U_-)
$Comp
L industrial-dual-analog-in-v2-rescue:C C7
U 1 1 50065789
P 1450 950
F 0 "C7" H 1500 1050 50  0000 L CNN
F 1 "10uF" H 1500 850 50  0000 L CNN
F 2 "kicad-libraries:C0805" H 1450 950 60  0001 C CNN
F 3 "" H 1450 950 60  0001 C CNN
	1    1450 950 
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:CON-SENSOR2 P1
U 1 1 5A8FAB4C
P 850 1400
F 0 "P1" H 700 1800 60  0000 C CNN
F 1 "CON-SENSOR2" V 1000 1400 60  0000 C CNN
F 2 "kicad-libraries:CON-SENSOR2" H 950 1250 60  0001 C CNN
F 3 "" H 950 1250 60  0000 C CNN
	1    850  1400
	-1   0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C24
U 1 1 5A8FB1F7
P 1850 950
F 0 "C24" H 1900 1050 50  0000 L CNN
F 1 "1uF" H 1900 850 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 1850 950 60  0001 C CNN
F 3 "" H 1850 950 60  0001 C CNN
	1    1850 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 6650 5900 6650
Wire Wire Line
	5900 6650 5900 7500
Wire Wire Line
	4500 6850 4500 7500
Wire Wire Line
	6200 7500 6200 7350
Wire Wire Line
	6200 6750 6200 6950
Wire Wire Line
	5700 7500 5700 6850
Wire Wire Line
	5750 5250 5900 5250
Wire Wire Line
	5700 6050 5750 6050
Wire Wire Line
	5750 6050 5750 5250
Connection ~ 5900 5250
Wire Wire Line
	5700 6150 6350 6150
Wire Wire Line
	6350 6150 6350 5250
Wire Wire Line
	6350 5250 6650 5250
Connection ~ 6650 5250
Wire Wire Line
	5900 5700 5900 5650
Wire Wire Line
	6150 5700 6150 5650
Wire Wire Line
	6650 5700 6650 5650
Wire Wire Line
	6900 5700 6900 5650
Wire Wire Line
	6650 5250 6650 5200
Wire Wire Line
	5900 5250 5900 5200
Wire Wire Line
	5900 4700 5900 4650
Wire Wire Line
	6650 4700 6650 4650
Wire Wire Line
	1400 6300 1400 6350
Wire Wire Line
	6450 1300 6450 1000
Wire Wire Line
	6450 1000 6200 1000
Wire Wire Line
	5450 1400 5450 1000
Wire Wire Line
	5450 1000 5700 1000
Wire Wire Line
	6500 1300 6450 1300
Wire Wire Line
	6500 1500 6450 1500
Wire Wire Line
	6450 1500 6450 1600
Wire Wire Line
	7150 1600 7300 1600
Wire Wire Line
	7150 1600 7150 1500
Wire Wire Line
	7150 1500 7000 1500
Wire Wire Line
	7000 1300 7150 1300
Wire Wire Line
	7150 1300 7150 1200
Wire Wire Line
	7150 1200 7300 1200
Wire Wire Line
	7300 1200 7300 1150
Wire Wire Line
	7300 1650 7300 1600
Wire Wire Line
	1400 7250 1400 7350
Connection ~ 6450 1500
Connection ~ 6450 1300
Connection ~ 7300 1200
Connection ~ 7300 1600
Wire Wire Line
	7450 650  7450 600 
Wire Wire Line
	7450 600  7300 600 
Wire Wire Line
	7300 600  7300 750 
Wire Wire Line
	7300 2050 7300 2500
Wire Wire Line
	8500 1350 8500 1400
Wire Wire Line
	8500 1400 8650 1400
Wire Wire Line
	8650 1400 8650 1450
Connection ~ 8500 1400
Wire Wire Line
	8150 1950 8500 1950
Wire Wire Line
	7650 1600 7650 1950
Wire Wire Line
	7650 1200 7650 850 
Wire Wire Line
	8150 850  8500 850 
Connection ~ 8500 850 
Connection ~ 8500 1950
Wire Wire Line
	6450 2500 6450 2100
Wire Wire Line
	4900 2500 4900 1850
Wire Wire Line
	5400 1400 5450 1400
Wire Wire Line
	4900 1400 4900 1450
Wire Wire Line
	4650 1400 4900 1400
Connection ~ 5450 1400
Connection ~ 4900 1400
Wire Wire Line
	6450 3400 6450 3100
Wire Wire Line
	6450 3100 6200 3100
Wire Wire Line
	5450 3500 5450 3100
Wire Wire Line
	5450 3100 5700 3100
Wire Wire Line
	6500 3400 6450 3400
Wire Wire Line
	6500 3600 6450 3600
Wire Wire Line
	6450 3600 6450 3700
Wire Wire Line
	7150 3700 7300 3700
Wire Wire Line
	7150 3700 7150 3600
Wire Wire Line
	7150 3600 7000 3600
Wire Wire Line
	7000 3400 7150 3400
Wire Wire Line
	7150 3400 7150 3300
Wire Wire Line
	7150 3300 7300 3300
Wire Wire Line
	7300 3300 7300 3250
Wire Wire Line
	7300 3750 7300 3700
Connection ~ 6450 3600
Connection ~ 6450 3400
Connection ~ 7300 3300
Connection ~ 7300 3700
Wire Wire Line
	7450 2750 7450 2700
Wire Wire Line
	7450 2700 7300 2700
Wire Wire Line
	7300 2700 7300 2850
Wire Wire Line
	7300 4150 7300 4600
Wire Wire Line
	8500 3450 8500 3500
Wire Wire Line
	8500 3500 8650 3500
Wire Wire Line
	8650 3500 8650 3550
Connection ~ 8500 3500
Wire Wire Line
	8150 4050 8500 4050
Wire Wire Line
	7650 3700 7650 4050
Wire Wire Line
	7650 3300 7650 2950
Wire Wire Line
	8150 2950 8500 2950
Connection ~ 8500 2950
Connection ~ 8500 4050
Wire Wire Line
	6450 4600 6450 4200
Wire Wire Line
	4900 4600 4900 3950
Wire Wire Line
	5400 3500 5450 3500
Wire Wire Line
	4900 3500 4900 3550
Wire Wire Line
	4650 3500 4900 3500
Connection ~ 5450 3500
Connection ~ 4900 3500
Wire Wire Line
	5700 6450 6250 6450
Wire Wire Line
	6250 6350 6250 6450
Wire Wire Line
	5700 6350 6250 6350
Connection ~ 6250 6450
Wire Wire Line
	6350 6550 5700 6550
Wire Wire Line
	5700 6250 6350 6250
Wire Wire Line
	9850 4050 9850 3050
Wire Wire Line
	850  6850 850  6950
Wire Wire Line
	1400 6350 1050 6350
Wire Wire Line
	1050 6350 1050 6400
Connection ~ 1400 6350
Wire Wire Line
	1050 6800 1050 6850
Wire Wire Line
	1050 6850 850  6850
Connection ~ 1050 6850
Wire Wire Line
	1050 7350 1400 7350
Wire Wire Line
	1050 7350 1050 7300
Connection ~ 1400 7350
Wire Wire Line
	2700 6850 2850 6850
Wire Wire Line
	2700 6600 2850 6600
Wire Wire Line
	2100 6550 2100 6600
Wire Wire Line
	4500 5950 4200 5950
Wire Wire Line
	4500 6050 4100 6050
Wire Wire Line
	4000 6150 4500 6150
Wire Wire Line
	3900 6250 4500 6250
Wire Wire Line
	2750 7600 2750 7400
Connection ~ 3200 6600
Wire Wire Line
	3200 6600 3250 6600
Connection ~ 3800 6600
Wire Wire Line
	3750 6600 3800 6600
Wire Wire Line
	3800 7500 3800 7400
Connection ~ 3800 6850
Connection ~ 3200 6850
Wire Wire Line
	3200 7500 3200 7400
Wire Wire Line
	3800 6450 3800 6600
Wire Wire Line
	4500 6450 3800 6450
Wire Wire Line
	3200 6350 3200 6600
Wire Wire Line
	4500 6350 3200 6350
Wire Wire Line
	2250 7400 2250 7600
Connection ~ 2100 6600
Wire Wire Line
	1400 5550 1150 5550
Wire Wire Line
	1150 5550 1150 5650
Wire Wire Line
	2300 5550 2350 5550
Wire Wire Line
	2300 5400 2900 5400
Wire Wire Line
	2900 5400 2900 5250
Wire Wire Line
	2900 5250 2750 5250
Wire Wire Line
	2350 5250 2300 5250
Wire Wire Line
	1150 5650 1000 5650
Wire Wire Line
	1000 5650 1000 5700
Wire Wire Line
	1400 5250 1250 5250
Wire Wire Line
	1000 5250 1000 5050
Wire Wire Line
	1400 5400 1250 5400
Wire Wire Line
	1250 5400 1250 5250
Connection ~ 1250 5250
Connection ~ 1000 5650
Connection ~ 1000 5250
Wire Wire Line
	2650 5950 2650 6050
Wire Wire Line
	2350 5950 2350 6050
Connection ~ 2650 5550
Connection ~ 2350 5550
Wire Wire Line
	9800 850  9800 2450
Wire Wire Line
	9800 2450 10150 2450
Wire Wire Line
	9900 1950 9900 2350
Wire Wire Line
	9900 2350 10150 2350
Wire Wire Line
	9550 2650 10150 2650
Wire Wire Line
	9250 2750 10150 2750
Wire Wire Line
	9850 3050 10150 3050
Wire Wire Line
	5700 5950 5700 6050
Connection ~ 5700 6050
Wire Wire Line
	5700 6750 6200 6750
Wire Wire Line
	4500 6550 3650 6550
Wire Wire Line
	3650 6550 3650 6000
Wire Wire Line
	3650 5500 3650 5450
Wire Wire Line
	10050 2550 10050 2850
Wire Wire Line
	10050 2850 10150 2850
Wire Wire Line
	10050 2550 10150 2550
Connection ~ 10050 2850
Wire Wire Line
	9550 2550 9550 2650
Wire Wire Line
	9550 2050 9550 1900
Wire Wire Line
	9250 2550 9250 2750
Wire Wire Line
	9250 2050 9250 1900
Connection ~ 9250 2750
Connection ~ 9550 2650
Wire Wire Line
	9550 3600 9550 3550
Wire Wire Line
	9250 3600 9250 3550
Wire Wire Line
	1200 1300 1300 1300
Wire Wire Line
	1300 1300 1300 700 
Wire Wire Line
	1300 700  1450 700 
Wire Wire Line
	1850 650  1850 700 
Wire Wire Line
	1450 750  1450 700 
Connection ~ 1450 700 
Connection ~ 1850 700 
Wire Wire Line
	1200 1100 1250 1100
Wire Wire Line
	1250 1100 1250 650 
Wire Wire Line
	1200 1200 1450 1200
Wire Wire Line
	1450 1200 1450 1150
Wire Wire Line
	1850 1150 1850 1200
Connection ~ 1450 1200
Connection ~ 1850 1200
$Comp
L industrial-dual-analog-in-v2-rescue:C C23
U 1 1 5A8FE488
P 1300 2000
F 0 "C23" H 1350 2100 50  0000 L CNN
F 1 "220pF" H 1350 1900 50  0000 L CNN
F 2 "kicad-libraries:C0402F" H 1300 2000 60  0001 C CNN
F 3 "" H 1300 2000 60  0001 C CNN
	1    1300 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 1400 1550 1400
Wire Wire Line
	1200 1500 1450 1500
Wire Wire Line
	1200 1600 1600 1600
Wire Wire Line
	1200 1700 1300 1700
Wire Wire Line
	1300 1800 1300 1700
Connection ~ 1300 1700
Wire Wire Line
	1300 2250 1300 2200
Wire Wire Line
	850  2250 850  1850
Text GLabel 2500 1700 2    47   Input ~ 0
S-MISO
Text GLabel 2500 1600 2    47   Output ~ 0
S-MOSI
Text GLabel 2500 1500 2    47   Output ~ 0
S-CLK
Text GLabel 2500 1400 2    47   Output ~ 0
S-CS
Text GLabel 1500 3950 0    47   Output ~ 0
S-MISO
Text GLabel 3300 3000 0    47   Input ~ 0
S-MOSI
Text GLabel 3300 3100 0    47   Input ~ 0
S-CLK
Text GLabel 1500 4150 0    47   Input ~ 0
S-CS
$Comp
L industrial-dual-analog-in-v2-rescue:XMC1XXX24 U3
U 3 1 5A90510B
P 3900 2950
F 0 "U3" H 3750 3200 60  0000 C CNN
F 1 "XMC1100" H 3900 2700 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 4050 3700 60  0001 C CNN
F 3 "" H 4050 3700 60  0000 C CNN
	3    3900 2950
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:XMC1XXX24 U3
U 2 1 5A905284
P 2050 4100
F 0 "U3" H 1900 4650 60  0000 C CNN
F 1 "XMC1100" H 2050 3550 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 2200 4850 60  0001 C CNN
F 3 "" H 2200 4850 60  0000 C CNN
	2    2050 4100
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:XMC1XXX24 U3
U 4 1 5A90538B
P 3900 4200
F 0 "U3" H 3750 4650 60  0000 C CNN
F 1 "XMC1100" H 3900 3750 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 4050 4950 60  0001 C CNN
F 3 "" H 4050 4950 60  0000 C CNN
	4    3900 4200
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:XMC1XXX24 U3
U 1 1 5A90547B
P 3650 1300
F 0 "U3" H 3500 1700 60  0000 C CNN
F 1 "XMC1100" H 3650 900 60  0000 C CNN
F 2 "kicad-libraries:QFN24-4x4mm-0.5mm" H 3800 2050 60  0001 C CNN
F 3 "" H 3800 2050 60  0000 C CNN
	1    3650 1300
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:C C25
U 1 1 5A9074FD
P 3150 1250
F 0 "C25" H 3200 1350 50  0000 L CNN
F 1 "100nF" H 3200 1150 50  0000 L CNN
F 2 "kicad-libraries:C0603F" H 3150 1250 60  0001 C CNN
F 3 "" H 3150 1250 60  0001 C CNN
	1    3150 1250
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:3V3 #PWR045
U 1 1 5A907E1D
P 3150 950
F 0 "#PWR045" H 3150 1050 40  0001 C CNN
F 1 "3V3" H 3150 1075 40  0000 C CNN
F 2 "" H 3150 950 60  0001 C CNN
F 3 "" H 3150 950 60  0001 C CNN
	1    3150 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 950  3150 1000
Wire Wire Line
	3300 1000 3150 1000
Connection ~ 3150 1000
Wire Wire Line
	3150 1650 3150 1600
Wire Wire Line
	3300 1500 3150 1500
Connection ~ 3150 1500
Wire Wire Line
	3150 1600 3300 1600
Connection ~ 3150 1600
Wire Notes Line
	4300 500  4300 4900
Wire Notes Line
	4300 4900 450  4900
Wire Wire Line
	3550 3000 3300 3000
Wire Wire Line
	3300 3100 3550 3100
Wire Wire Line
	1500 3950 1700 3950
Wire Wire Line
	1500 4150 1700 4150
$Comp
L industrial-dual-analog-in-v2-rescue:CONN_01X01 P4
U 1 1 5A914F62
P 3100 3950
F 0 "P4" H 3100 4050 50  0000 C CNN
F 1 "DEBUG" V 3200 3950 50  0000 C CNN
F 2 "kicad-libraries:DEBUG_PAD" H 3100 3950 50  0001 C CNN
F 3 "" H 3100 3950 50  0000 C CNN
	1    3100 3950
	-1   0    0    1   
$EndComp
Wire Wire Line
	3300 3950 3550 3950
$Comp
L industrial-dual-analog-in-v2-rescue:CONN_01X02 P5
U 1 1 5A91ABEA
P 3200 4500
F 0 "P5" H 3200 4650 50  0000 C CNN
F 1 "DEBUG" V 3300 4500 50  0000 C CNN
F 2 "kicad-libraries:SolderJumper" H 3200 4500 50  0001 C CNN
F 3 "" H 3200 4500 50  0000 C CNN
	1    3200 4500
	-1   0    0    1   
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:LED D3
U 1 1 5A91DE95
P 2700 2400
F 0 "D3" H 2700 2300 50  0000 C CNN
F 1 "blue" H 2850 2300 50  0000 C CNN
F 2 "kicad-libraries:D0603F" H 2700 2400 50  0001 C CNN
F 3 "" H 2700 2400 50  0000 C CNN
	1    2700 2400
	1    0    0    -1  
$EndComp
Text GLabel 1000 4350 0    47   Output ~ 0
M-CS
Text GLabel 1000 4450 0    47   Output ~ 0
M-CLK
Text GLabel 1000 4550 0    47   Input ~ 0
M-MISO
Wire Wire Line
	1700 4350 1500 4350
Wire Wire Line
	1500 4450 1700 4450
Wire Wire Line
	1500 4550 1700 4550
Text GLabel 1000 4650 0    47   Output ~ 0
M-MOSI
$Comp
L industrial-dual-analog-in-v2-rescue:R_PACK4 RP2
U 1 1 5A9325DA
P 1300 4700
F 0 "RP2" H 1300 5150 50  0000 C CNN
F 1 "82" H 1300 4650 50  0000 C CNN
F 2 "kicad-libraries:4X0402" H 1300 4700 50  0001 C CNN
F 3 "" H 1300 4700 50  0000 C CNN
	1    1300 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 4350 1100 4350
Wire Wire Line
	1100 4450 1000 4450
Wire Wire Line
	1100 4550 1000 4550
Text Notes 900  2800 0    39   ~ 0
SPI Slave\nP1.2 : USIC0_CH1-DOUT0 : MOSI\nP0.7 : USIC0_CH1-DX0D : MISO\nP1.3 : USIC0_CH1-SCLKOUT: CLK\nP0.9 : USIC0_CH1-DX2B : SEL\n
Text Notes 900  3150 0    39   ~ 0
SPI Master\nP0.13 : USIC0_CH0-SELO4    : SEL\nP0.14 : USIC0_CH0-SCLKOUT : CLK\nP0.15 : USIC0_CH0-DX0B    : MISO\nP2.0  : USIC0_CH0-DOUT0   : MOSI
NoConn ~ 1700 3750
NoConn ~ 1700 3850
NoConn ~ 1700 4050
NoConn ~ 1700 4250
NoConn ~ 3550 4550
NoConn ~ 3550 4350
NoConn ~ 3550 4250
NoConn ~ 3550 4150
NoConn ~ 3550 4050
Text GLabel 3900 5900 1    47   Input ~ 0
M-CS
Text GLabel 4000 5900 1    47   Input ~ 0
M-CLK
Text GLabel 4100 5900 1    47   Output ~ 0
M-MISO
Text GLabel 4200 5900 1    47   Input ~ 0
M-MOSI
Wire Wire Line
	3900 6250 3900 5900
Wire Wire Line
	4000 6150 4000 5900
Wire Wire Line
	4100 6050 4100 5900
Wire Wire Line
	4200 5950 4200 5900
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR046
U 1 1 5A951F2C
P 3450 4600
F 0 "#PWR046" H 3450 4600 40  0001 C CNN
F 1 "DGND" H 3450 4530 40  0000 C CNN
F 2 "" H 3450 4600 60  0000 C CNN
F 3 "" H 3450 4600 60  0000 C CNN
	1    3450 4600
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR047
U 1 1 5A952BDB
P 1300 2250
F 0 "#PWR047" H 1300 2250 40  0001 C CNN
F 1 "DGND" H 1300 2180 40  0000 C CNN
F 2 "" H 1300 2250 60  0000 C CNN
F 3 "" H 1300 2250 60  0000 C CNN
	1    1300 2250
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR048
U 1 1 5A9532A3
P 850 2250
F 0 "#PWR048" H 850 2250 40  0001 C CNN
F 1 "DGND" H 850 2180 40  0000 C CNN
F 2 "" H 850 2250 60  0000 C CNN
F 3 "" H 850 2250 60  0000 C CNN
	1    850  2250
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR049
U 1 1 5A953648
P 3150 1650
F 0 "#PWR049" H 3150 1650 40  0001 C CNN
F 1 "DGND" H 3150 1580 40  0000 C CNN
F 2 "" H 3150 1650 60  0000 C CNN
F 3 "" H 3150 1650 60  0000 C CNN
	1    3150 1650
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR050
U 1 1 5A953BB4
P 1850 1250
F 0 "#PWR050" H 1850 1250 40  0001 C CNN
F 1 "DGND" H 1850 1180 40  0000 C CNN
F 2 "" H 1850 1250 60  0000 C CNN
F 3 "" H 1850 1250 60  0000 C CNN
	1    1850 1250
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:R_PACK4 RP1
U 1 1 5A8FDCDF
P 2000 1750
F 0 "RP1" H 2000 2200 50  0000 C CNN
F 1 "82" H 2000 1700 50  0000 C CNN
F 2 "kicad-libraries:4X0402" H 2000 1750 50  0001 C CNN
F 3 "" H 2000 1750 50  0000 C CNN
	1    2000 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1700 1500 1450
Wire Wire Line
	1500 1450 1650 1450
Wire Wire Line
	1650 1450 1650 1400
Wire Wire Line
	1650 1400 1800 1400
Wire Wire Line
	1600 1600 1600 1500
Wire Wire Line
	1600 1500 1800 1500
Wire Wire Line
	1450 1500 1450 1550
Wire Wire Line
	1450 1550 1700 1550
Wire Wire Line
	1700 1550 1700 1600
Wire Wire Line
	1700 1600 1800 1600
Wire Wire Line
	1550 1400 1550 1700
Wire Wire Line
	1550 1700 1800 1700
Wire Wire Line
	2200 1700 2250 1700
Wire Wire Line
	2250 1700 2250 1450
Wire Wire Line
	2250 1450 2450 1450
Wire Wire Line
	2450 1450 2450 1400
Wire Wire Line
	2450 1400 2500 1400
Wire Wire Line
	2200 1500 2300 1500
Wire Wire Line
	2300 1500 2300 1600
Wire Wire Line
	2300 1600 2500 1600
Wire Wire Line
	2200 1400 2350 1400
Wire Wire Line
	2350 1400 2350 1700
Wire Wire Line
	2350 1700 2500 1700
Wire Wire Line
	2200 1600 2200 1550
Wire Wire Line
	2200 1550 2400 1550
Wire Wire Line
	2400 1550 2400 1500
Wire Wire Line
	2400 1500 2500 1500
Wire Wire Line
	1100 4650 1000 4650
Text GLabel 1800 4750 2    47   Input ~ 0
P0.2
Wire Wire Line
	1800 4750 1600 4750
Wire Wire Line
	1600 4750 1600 4650
Wire Wire Line
	1600 4650 1500 4650
Text GLabel 3400 3850 0    47   Output ~ 0
P0.2
Wire Wire Line
	3400 3850 3550 3850
Wire Wire Line
	3400 4450 3550 4450
Wire Wire Line
	3400 4550 3450 4550
Wire Wire Line
	3450 4550 3450 4600
Wire Wire Line
	2100 6600 2200 6600
Wire Wire Line
	2100 6850 2200 6850
$Comp
L industrial-dual-analog-in-v2-rescue:CRYSTAL_3225 X1
U 1 1 5AABFE45
P 3500 6850
F 0 "X1" H 3300 7100 60  0000 C CNN
F 1 "4MHz" H 3500 6650 60  0000 C CNN
F 2 "kicad-libraries:HC49_US" H 3500 6850 60  0001 C CNN
F 3 "" H 3500 6850 60  0000 C CNN
	1    3500 6850
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:DGND #PWR051
U 1 1 5AAC0F5F
P 3350 7500
F 0 "#PWR051" H 3350 7500 40  0001 C CNN
F 1 "DGND" H 3350 7430 40  0000 C CNN
F 2 "" H 3350 7500 60  0000 C CNN
F 3 "" H 3350 7500 60  0000 C CNN
	1    3350 7500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 7150 3350 7500
$Comp
L industrial-dual-analog-in-v2-rescue:R_PACK4 RP3
U 1 1 5AAC2CED
P 3150 2450
F 0 "RP3" H 3150 2900 50  0000 C CNN
F 1 "1k" H 3150 2400 50  0000 C CNN
F 2 "kicad-libraries:4X0402" H 3150 2450 50  0001 C CNN
F 3 "" H 3150 2450 50  0000 C CNN
	1    3150 2450
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:LED D4
U 1 1 5AAC3241
P 2700 2100
F 0 "D4" H 2700 2200 50  0000 C CNN
F 1 "blue" H 2850 2200 50  0000 C CNN
F 2 "kicad-libraries:D0603F" H 2700 2100 50  0001 C CNN
F 3 "" H 2700 2100 50  0000 C CNN
	1    2700 2100
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:LED D5
U 1 1 5AAC3451
P 2700 2200
F 0 "D5" H 2700 2100 50  0000 C CNN
F 1 "blue" H 2850 2100 50  0000 C CNN
F 2 "kicad-libraries:D0603F" H 2700 2200 50  0001 C CNN
F 3 "" H 2700 2200 50  0000 C CNN
	1    2700 2200
	1    0    0    -1  
$EndComp
$Comp
L industrial-dual-analog-in-v2-rescue:3V3 #PWR052
U 1 1 5AAC35ED
P 2500 2050
F 0 "#PWR052" H 2500 2150 40  0001 C CNN
F 1 "3V3" H 2500 2175 40  0000 C CNN
F 2 "" H 2500 2050 60  0001 C CNN
F 3 "" H 2500 2050 60  0001 C CNN
	1    2500 2050
	1    0    0    -1  
$EndComp
Connection ~ 2500 2100
Wire Wire Line
	2900 2100 2950 2100
Wire Wire Line
	3300 2900 3550 2900
Wire Wire Line
	3300 2800 3550 2800
NoConn ~ 2950 2300
NoConn ~ 3350 2300
Wire Wire Line
	2900 2400 2950 2400
Wire Wire Line
	2950 2200 2900 2200
Wire Wire Line
	2500 2050 2500 2100
Connection ~ 2500 2200
Text GLabel 3300 2800 0    47   Output ~ 0
LED0
Text GLabel 1500 3650 0    47   Output ~ 0
LEDS
Wire Wire Line
	1500 3650 1700 3650
Text GLabel 3300 2900 0    47   Output ~ 0
LED1
Text GLabel 3500 2100 2    47   Input ~ 0
LED1
Text GLabel 3500 2200 2    47   Input ~ 0
LED0
Text GLabel 3500 2400 2    47   Input ~ 0
LEDS
Wire Wire Line
	3350 2400 3500 2400
Wire Wire Line
	3500 2200 3350 2200
Wire Wire Line
	3350 2100 3500 2100
Wire Wire Line
	5900 5250 6150 5250
Wire Wire Line
	6650 5250 6900 5250
Wire Wire Line
	7300 1200 7650 1200
Wire Wire Line
	7300 1600 7650 1600
Wire Wire Line
	8500 1400 8500 1450
Wire Wire Line
	8500 850  9800 850 
Wire Wire Line
	8500 1950 9900 1950
Wire Wire Line
	7300 3300 7650 3300
Wire Wire Line
	7300 3700 7650 3700
Wire Wire Line
	8500 3500 8500 3550
Wire Wire Line
	8500 2950 10150 2950
Wire Wire Line
	8500 4050 9850 4050
Wire Wire Line
	6250 6450 6250 6600
Wire Wire Line
	1400 6350 1400 6450
Wire Wire Line
	1050 6850 1050 6900
Wire Wire Line
	1400 7350 1400 7400
Wire Wire Line
	1400 7350 1500 7350
Wire Wire Line
	3200 6600 3200 6850
Wire Wire Line
	3800 6600 3800 6850
Wire Wire Line
	3800 6850 3800 7000
Wire Wire Line
	3200 6850 3200 7000
Wire Wire Line
	2100 6600 2100 6850
Wire Wire Line
	1250 5250 1000 5250
Wire Wire Line
	2650 5550 2750 5550
Wire Wire Line
	2350 5550 2650 5550
Wire Wire Line
	10050 2850 10050 3250
Wire Wire Line
	9250 2750 9250 3050
Wire Wire Line
	9550 2650 9550 3050
Wire Wire Line
	1450 700  1850 700 
Wire Wire Line
	1850 700  1850 750 
Wire Wire Line
	1450 1200 1850 1200
Wire Wire Line
	1850 1200 1850 1250
Wire Wire Line
	1300 1700 1500 1700
Wire Wire Line
	3150 1000 3150 1050
Wire Wire Line
	3150 1500 3150 1450
Wire Wire Line
	3150 1600 3150 1500
Wire Wire Line
	2500 2100 2500 2200
Wire Wire Line
	2500 2200 2500 2400
$EndSCHEMATC
