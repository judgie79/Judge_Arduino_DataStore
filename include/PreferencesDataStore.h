#ifndef __PREFERENCESDATA_STORE_H
#define __PREFERENCESDATA_STORE_H

#if defined(ESP32)
#include "Arduino.h"
#include <Preferences.h>
#include "DataStore.h"

class PreferencesDataStore : public DataStore {
private:
    	Preferences preferences;
		const char * name;
public:
	PreferencesDataStore(const char * name);

	void begin(bool readonly = true);
	void end();

	bool readBool(const char *  key);
	int readInt(const char *  key);
	uint32_t readUInt(const char *key);
	int16_t readShort(const char *key);
	uint16_t readUShort(const char *key);
	String readString(const char *  key);
	char readChar(const char *  key);

	void write(const char *  key, bool value);
	void write(const char *  key, int value);
	void write(const char *  key, uint32_t value);
	void write(const char *  key, int16_t value);
	void write(const char *  key, uint16_t value);
	void write(const char *  key, String value);
	void write(const char *  key, char value);
};

#endif

#endif