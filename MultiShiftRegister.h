#ifndef MultiShiftRegister_h
#define MultiShiftRegister_h

#if ARDUINO >= 100
#include "Arduino.h" 
#else
#include "WProgram.h"
#endif

class MultiShiftRegister {
    int m_latchPin, m_clockPin, m_dataPin, m_totalOutputPins, m_totalShiftRegisters;
    int* m_data;
  public:
    MultiShiftRegister (int, int, int, int);
    ~MultiShiftRegister();
    void set_shift(int);
    void set(int);
    void clear_shift(int);
    void clear(int);
    void shift();
  private:
    int getRegisterPin(int);
    int getRegisterNumber(int);
};

#endif
