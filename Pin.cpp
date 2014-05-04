#pragma once

#include <Arduino.h>

/**
 * Виртуальный базовый класс
 */
class Pin
{
protected:
  int pin;

public:
  Pin(int pin)
  {
    this->pin = pin;
  };

  virtual ~Pin()
  {
  }

  int getPin()
  {
    return this->pin;
  };

  boolean isOn()
  {
    return (boolean)digitalRead(this->pin);
  };

  boolean isOff()
  {
    return !this->isOn();
  };
};

/**
 * Цифровые входы
 */
class Sensor : public Pin
{
public:
  Sensor(int pin) : Pin(pin)
  {
    pinMode(pin, INPUT);
  };
  
  Sensor(int pin, boolean pullup) : Pin(pin)
  {
    pinMode(pin, (pullup ? INPUT_PULLUP : INPUT));
  };
};

/**
 * Цифровые выходы
 */
class DigitalOutput : public Pin
{
  boolean inversion; // инверсия команд для реле

public:
  DigitalOutput(int pin) : Pin(pin)
  {
    pinMode(pin, OUTPUT);
    this->inversion = false;
    this->off();
  };

  DigitalOutput(int pin, boolean inversion) : Pin(pin)
  {
    pinMode(pin, OUTPUT);
    this->inversion = inversion;
    this->off();
  };

  void on()
  {
    digitalWrite(this->pin, (this->inversion) ? LOW : HIGH);
  };

  void off()
  {
    digitalWrite(this->pin, (this->inversion) ? HIGH : LOW);
  };
};

/**
 * Режим реле
 * Является коротким вариантом new Sensor(pin, true);
 */
class Relay : public DigitalOutput
{
public:
   Relay(int pin) : DigitalOutput(pin, true)
   {
   };
};


