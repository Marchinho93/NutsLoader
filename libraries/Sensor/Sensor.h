//
// Created by Marco Bramini on 19/12/17.
//

#ifndef NUTSLOADER_SENSOR_H
#define NUTSLOADER_SENSOR_H

#include "Arduino.h"

class Sensor{
	public:
        Sensor(int trig, int echo);
		int readValue();
	private:
		void trigger();
		int receiveEcho();
		int getNormalizedValue(long echoTime);
		int trig, echo;
};

#endif //NUTSLOADER_SENSOR_H
