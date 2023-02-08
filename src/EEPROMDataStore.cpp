#include "EEPROMDataStore.h"
#include "DataStore.h"
#if !defined(ESP32)
#include <EEPROM.h>
EEPROMDataStore::EEPROMDataStore() :
    DataStore()
{
    
}

void EEPROMDataStore::begin() 
{

}

bool EEPROMDataStore::canAccess(uint16_t address)
{
    return address < EEPROM.length();
}

byte EEPROMDataStore::read(int address)
{
    if (canAccess(address)) {
        return (byte)EEPROM.read(address);
    }
    return -1;
}

void EEPROMDataStore::write(int address, byte value)
{
    if (canAccess(address)) {
        return EEPROM.write(address, value);
    }
}
#endif