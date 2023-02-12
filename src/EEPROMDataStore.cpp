#include "EEPROMDataStore.h"
#include "DataStore.h"
#if !defined(ESP32)
#include <EEPROM.h>

EEPROMDataStore::EEPROMDataStore(StoreMap storeMap) : DataStore()
{
    this->storeMap = storeMap;
}

void EEPROMDataStore::begin(bool readonly)
{
    this->readonly = readonly;
}

void EEPROMDataStore::end()
{
    this->readonly = true;
}

bool EEPROMDataStore::readBool(const char *key)
{
    if (canAccess(storeMap(key)))
    {
        return (bool)EEPROM.read(storeMap(key));
    }
    return -1;
}
int EEPROMDataStore::readInt(const char *key)
{
    if (canAccess(storeMap(key)))
    {
        return (EEPROM.read(storeMap(key)) << 8) + EEPROM.read(storeMap(key) + 1);
    }
    return -1;
}

unsigned int EEPROMDataStore::readUInt(const char *key)
{
    if (canAccess(storeMap(key)))
    {
        return (EEPROM.read(storeMap(key)) << 8) + EEPROM.read(storeMap(key) + 1);
    }
    return -1;
}

unsigned short EEPROMDataStore::readUShort(const char *key)
{
    if (canAccess(storeMap(key)))
    {
        return EEPROM.read(storeMap(key));
    }
    return -1;
}

short EEPROMDataStore::readShort(const char *key)
{
    if (canAccess(storeMap(key)))
    {
        return EEPROM.read(storeMap(key));
    }
    return -1;
}

String EEPROMDataStore::readString(const char *key)
{
    if (canAccess(storeMap(key)))
    {
        int newStrLen = EEPROM.read(storeMap(key));
        char data[newStrLen + 1];
        for (int i = 0; i < newStrLen; i++)
        {
            data[i] = EEPROM.read(storeMap(key) + 1 + i);
        }
        data[newStrLen] = '\0';
        return String(data);
    }
    return "";
}

char EEPROMDataStore::readChar(const char *key)
{
    if (canAccess(storeMap(key)))
    {
        return (char)EEPROM.read(storeMap(key));
    }
    return -1;
}

void EEPROMDataStore::writeBool(const char *key, bool value)
{
    if (readonly)
        return;

    if (canAccess(storeMap(key)))
    {
        return EEPROM.write(storeMap(key), value);
    }
}

void EEPROMDataStore::writeInt(const char *key, int value)
{
    if (readonly)
        return;

    if (canAccess(storeMap(key)))
    {
        EEPROM.write(storeMap(key), value >> 8);
        EEPROM.write(storeMap(key) + 1, value & 0xFF);
    }
}

void EEPROMDataStore::writeUShort(const char *key, unsigned short value)
{
    if (readonly)
        return;

    if (canAccess(storeMap(key)))
    {
        EEPROM.write(storeMap(key), value);
    }
}
void EEPROMDataStore::writeShort(const char *key, short value)
{
    if (readonly)
        return;

    if (canAccess(storeMap(key)))
    {
        return EEPROM.write(storeMap(key), value);
    }
}

void EEPROMDataStore::writeUInt(const char *key, unsigned int value)
{
    if (readonly)
        return;

    if (canAccess(storeMap(key)))
    {
        EEPROM.write(storeMap(key), value >> 8);
        EEPROM.write(storeMap(key) + 1, value & 0xFF);
    }
}

void EEPROMDataStore::writeString(const char *key, String value)
{
    if (readonly)
        return;

    if (canAccess(storeMap(key)))
    {
        byte len = value.length();
        EEPROM.write(storeMap(key), len);
        for (int i = 0; i < len; i++)
        {
            EEPROM.write(storeMap(key) + 1 + i, value[i]);
        }
    }
}

void EEPROMDataStore::writeChar(const char *key, char value)
{
    if (readonly)
        return;

    if (canAccess(storeMap(key)))
    {
        return EEPROM.write(storeMap(key), value);
    }
}

bool EEPROMDataStore::canAccess(uint16_t address)
{
    return address < EEPROM.length();
}

#endif