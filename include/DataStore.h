#ifndef __DataStore_h
#define __DataStore_h

#include <Arduino.h>

class DataStore {
private:

public:
	DataStore()
	{}

	virtual void begin(bool readonly = true);
	virtual void end();

	virtual bool readBool(const char *  key);
	virtual int readInt(const char *  key);
	virtual String readString(const char *  key);
	virtual char readChar(const char *  key);

	virtual void writeBool(const char *  key, bool value);
	virtual void writeInt(const char *  key, int value);
	virtual void writeString(const char *  key, String value);
	virtual void writeChar(const char *  key, char value);
	virtual void writeShort(const char *  key, short value);
	virtual void writeUShort(const char *  key, unsigned short value);
	virtual void writeUInt(const char *  key, unsigned int value);
};
#endif