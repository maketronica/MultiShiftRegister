#include <MultiShiftRegister.h>

MultiShiftRegister::MultiShiftRegister(int a_totalShiftRegisters, int a_latchPin, int a_clockPin, int a_dataPin) {
  m_latchPin = a_latchPin;
  m_clockPin = a_clockPin;
  m_dataPin = a_dataPin;
  m_totalShiftRegisters = a_totalShiftRegisters;
  m_totalOutputPins = a_totalShiftRegisters * 8;
  m_data = new int[a_totalShiftRegisters]();
}

MultiShiftRegister::~MultiShiftRegister(void) {
  delete[] m_data;
}

void MultiShiftRegister::set_shift(int outputPin) {
  set(outputPin);
  shift();
}

void MultiShiftRegister::clear_shift(int outputPin) {
  clear(outputPin);
  shift();
}

void MultiShiftRegister::set(int outputPin) {
  int registerPin = getRegisterPin(outputPin);
  int registerNumber = getRegisterNumber(outputPin);
  bitSet(m_data[registerNumber], registerPin);
}

void MultiShiftRegister::clear(int outputPin) {
  int registerPin = getRegisterPin(outputPin);
  int registerNumber = getRegisterNumber(outputPin);
  bitClear(m_data[registerNumber], registerPin);
}

int MultiShiftRegister::getRegisterPin(int outputPin) {
  return outputPin % 8;  
}

int MultiShiftRegister::getRegisterNumber(int outputPin) {
  return outputPin / 8;  
}

void MultiShiftRegister::shift() {
  digitalWrite(m_latchPin, LOW);
  for(int i=m_totalShiftRegisters-1; i>=0; i--) {
    shiftOut(m_dataPin, m_clockPin, MSBFIRST, m_data[i]);
  }
  digitalWrite(m_latchPin, HIGH);
}
