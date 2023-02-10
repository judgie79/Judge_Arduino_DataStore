#ifndef __DataStore_h
#define __DataStore_h

#include <Arduino.h>

class DataStore {
private:

public:
	DataStore()
  {
    
  }

	virtual void begin(bool readonly = true);
	virtual void end();

	virtual bool readBool(const char *  key);
	virtual int readInt(const char *  key);
	virtual String readString(const char *  key);
	virtual char readChar(const char *  key);

	virtual void write(const char *  key, bool value);
	virtual void write(const char *  key, int value);
	virtual void write(const char *  key, String value);
	virtual void write(const char *  key, char value);
};

#endif