#pragma once
#include "FreeRTOS_interrupts.h"

void ResetISR() __attribute__ ((noreturn));
void NmiSR();
void FaultISR();
void IntDefaultHandler();
