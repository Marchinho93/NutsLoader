#include "Arduino.h"
#include "Sensor.h"

Sensor::Sensor(int trig, int echo) {
	this->trig = trig;
	pinMode(this->trig, OUTPUT);
	this->echo = echo;
	pinMode(this->echo, INPUT_PULLUP);
}

int Sensor::readValue() {
	trigger();
	return receiveEcho();
}

void Sensor::trigger() {
	digitalWrite(this->trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(this->trig, LOW);
}

int Sensor::receiveEcho(){
	long echoTime = pulseIn(this->echo, HIGH);
	return getNormalizedValue(echoTime);
}

int Sensor::getNormalizedValue(long echoTime) {
	return 0.017 * echoTime;
}
