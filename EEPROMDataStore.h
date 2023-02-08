#ifndef __EEPROMDATA_STORE_H
#define __EEPROMDATA_STORE_H

#if !defined(ESP32)
#include "Arduino.h"
#include <DebugLog.h>
#include <EEPROM.h>
#include "DataStore.h"

class EEPROMDataStore : public DataStore {
private:

public:
	EEPROMDataStore();

	void begin();

    bool canAccess(uint16_t address);

	byte read(int address);

	void write(int address, byte value);
};

#endif

#endif