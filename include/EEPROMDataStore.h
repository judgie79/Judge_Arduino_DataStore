#ifndef __EEPROMDATA_STORE_H
#define __EEPROMDATA_STORE_H

#if !defined(ESP32)
#include "Arduino.h"
#include <DebugLog.h>
#include <EEPROM.h>
#include "DataStore.h"

typedef uint16_t(*StoreMap)(const char *);

class EEPROMDataStore : public DataStore {
private:
	bool readonly = true;
	bool canAccess(uint16_t address);
	StoreMap storeMap;
public:
	EEPROMDataStore(StoreMap storeMap);

	void begin(bool readonly = true);
	void end();

	bool readBool(const char *  key);
	int readInt(const char *  key);
	unsigned int readUInt(const char *key);
	short readShort(const char *key);
	unsigned short readUShort(const char *key);
	String readString(const char *  key);
	char readChar(const char *  key);

	void write(const char *  key, bool value);
	void write(const char *  key, int value);
	void write(const char *  key, String value);
	void write(const char *  key, char value);
	void write(const char *  key, unsigned int value);
	void write(const char *  key, short value);
	void write(const char *  key, unsigned short value);
};

#endif

#endif