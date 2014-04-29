# Arduino Pin
Управление Pin в ООП стиле.

## Example

```c++

#include "Pin.cpp"

Sensor* motion = new Sensor(10); // датчик движения
Sensor* button1 = new Sensor(11); // выключатель 1

DigitalOutput* led1 = new DigitalOutput(13); // лампа 1
DigitalOutput* relay1 = new DigitalOutput(2, true); // реле 1

void loop(){
	if (button1->isOn() || motion->isOn()) {
		led1->on();
		relay1->on();
	}
	else {
		led1->off();
		relay1->off();
	}
}

```