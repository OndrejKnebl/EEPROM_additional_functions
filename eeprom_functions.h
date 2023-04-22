#ifndef EEPROM_FUNCTIONS_H
#define EEPROMFUNCTIONS_H

#include <Arduino.h>
#include "Adafruit_EEPROM_I2C.h"

void eraseEEPROM();

void readDoubledValues(uint16_t readWriteAddr, uint8_t *buffer, uint8_t *buffer2, uint16_t mySizeof);
void writeDoubledValues(uint16_t readWriteAddr, uint8_t *buffer, uint16_t mySizeof);

bool loadAndCompareInts(uint16_t readWriteAddr, int *newValue);
bool loadAndCompareUints(uint16_t readWriteAddr, uint32_t *newValue);
bool loadAndCompareFloats(uint16_t readWriteAddr, float *newValue);
bool loadAndCompareBools(uint16_t readWriteAddr, bool *newValue);

#endif
