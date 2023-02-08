#ifndef __DataStore_h
#define __DataStore_h

#include <Arduino.h>

class DataStore {
private:

public:
	DataStore()
  {
    
  }

	virtual void begin();

	virtual byte read(int address);

	virtual void write(int address, byte value);
};

#endif