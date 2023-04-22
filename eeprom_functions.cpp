#include "eeprom_functions.h"

extern Adafruit_EEPROM_I2C i2ceeprom;


void eraseEEPROM(){
    
  uint8_t val2 = 255;
  uint8_t buffer[sizeof(val2)];
  memcpy(buffer, (void *)&val2, sizeof(val2));

  for (uint16_t addr = 0; addr < 4096; addr++) {
    i2ceeprom.write(addr, buffer, sizeof(val2));
  }
}



void readDoubledValues(uint16_t readWriteAddr, uint8_t *buffer, uint8_t *buffer2, uint16_t mySizeof) {
    i2ceeprom.read(readWriteAddr, buffer, mySizeof);
    i2ceeprom.read(readWriteAddr + 0x800, buffer2, mySizeof);
}


void writeDoubledValues(uint16_t readWriteAddr, uint8_t *buffer, uint16_t mySizeof){
    i2ceeprom.write(readWriteAddr, buffer, mySizeof);
    i2ceeprom.write(readWriteAddr + 0x800, buffer, mySizeof);
}



bool loadAndCompareInts(uint16_t readWriteAddr, int *newValue){

    int tmpValue1 = 4321;
    int tmpValue2 = 12345;

    uint8_t buffer[sizeof(tmpValue1)];
    uint8_t buffer2[sizeof(tmpValue2)];

    readDoubledValues(readWriteAddr, buffer, buffer2, sizeof(tmpValue1));

    memcpy((void *)&tmpValue1, buffer, sizeof(tmpValue1));
    memcpy((void *)&tmpValue2, buffer2, sizeof(tmpValue2));

    if((tmpValue1 == tmpValue2)){
        *newValue = tmpValue1;
        return true;

    }else{    
        return false;
    }
}


bool loadAndCompareUints(uint16_t readWriteAddr, uint32_t *newValue){

    uint32_t tmpValue1 = 4321;
    uint32_t tmpValue2 = 12345;

    uint8_t buffer[sizeof(tmpValue1)];
    uint8_t buffer2[sizeof(tmpValue2)];

    readDoubledValues(readWriteAddr, buffer, buffer2, sizeof(tmpValue1));

    memcpy((void *)&tmpValue1, buffer, sizeof(tmpValue1));
    memcpy((void *)&tmpValue2, buffer2, sizeof(tmpValue2));

    if((tmpValue1 == tmpValue2)){
        *newValue = tmpValue1;
        return true;

    }else{   
        return false;
    }
}


bool loadAndCompareFloats(uint16_t readWriteAddr, float *newValue){

    float tmpValue1 = 4321.5;
    float tmpValue2 = 12345.6;

    uint8_t buffer[sizeof(tmpValue1)];
    uint8_t buffer2[sizeof(tmpValue2)];

    readDoubledValues(readWriteAddr, buffer, buffer2, sizeof(tmpValue1));

    memcpy((void *)&tmpValue1, buffer, sizeof(tmpValue1));
    memcpy((void *)&tmpValue2, buffer2, sizeof(tmpValue2));

    if((tmpValue1 == tmpValue2)){
        *newValue = tmpValue1;
        return true;

    }else{      
        return false;
    }
}


bool loadAndCompareBools(uint16_t readWriteAddr, bool *newValue){

    bool tmpValue1 = true;
    bool tmpValue2 = false;

    uint8_t buffer[sizeof(tmpValue1)];
    uint8_t buffer2[sizeof(tmpValue2)];

    readDoubledValues(readWriteAddr, buffer, buffer2, sizeof(tmpValue1));

    memcpy((void *)&tmpValue1, buffer, sizeof(tmpValue1));
    memcpy((void *)&tmpValue2, buffer2, sizeof(tmpValue2));

    if((tmpValue1 == tmpValue2)){
        *newValue = tmpValue1;
        return true;

    }else{
        return false;
    }
}