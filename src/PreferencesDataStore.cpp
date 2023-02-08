#include "PreferencesDataStore.h"

#if defined(ESP32)
PreferencesDataStore::PreferencesDataStore() :
    DataStore()
{
    
}

void PreferencesDataStore::begin() 
{
    
}

bool PreferencesDataStore::canAccess(uint16_t address)
{
    return true;
}

byte PreferencesDataStore::read(int address)
{
    return 0;
}

void PreferencesDataStore::write(int address, byte value)
{

}
#endif