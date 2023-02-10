#include "PreferencesDataStore.h"

#if defined(ESP32)
PreferencesDataStore::PreferencesDataStore(const char *name) : DataStore()
{
    this->name = name;
}

void PreferencesDataStore::begin(bool readonly)
{
    preferences.begin(name, readonly);
}

void PreferencesDataStore::end()
{
    preferences.end();
}

bool PreferencesDataStore::readBool(const char *key)
{
    return preferences.getBool(key);
}
int PreferencesDataStore::readInt(const char *key)
{
    return preferences.getInt(key);
}

uint32_t PreferencesDataStore::readUInt(const char *key)
{
    return preferences.getUInt(key);
}

uint16_t PreferencesDataStore::readUShort(const char *key)
{
    return preferences.getUShort(key);
}

int16_t PreferencesDataStore::readShort(const char *key)
{
    return preferences.getShort(key);
}

String PreferencesDataStore::readString(const char *key)
{
    return preferences.getString(key);
}
char PreferencesDataStore::readChar(const char *key)
{
    return preferences.getChar(key);
}

void PreferencesDataStore::write(const char *key, bool value)
{
    preferences.putBool(key, value);
}
void PreferencesDataStore::write(const char *key, int value)
{
    preferences.putInt(key, value);
}
void PreferencesDataStore::write(const char *key, String value)
{
    preferences.putString(key, value);
}
void PreferencesDataStore::write(const char *key, char value)
{
    preferences.putChar(key, value);
}

#endif