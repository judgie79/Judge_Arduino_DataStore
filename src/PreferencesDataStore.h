#ifndef __PREFERENCESDATA_STORE_H
#define __PREFERENCESDATA_STORE_H

#if defined(ESP32)
#include "Arduino.h"
#include <Preferences.h>

class PreferencesDataStore : public DataStore {
private:
    	Preferences preferences;
public:
	PreferencesDataStore();

	void begin();

    bool canAccess(uint16_t address);

	byte read(int address);

	void write(int address, byte value);
};

#endif

#endif