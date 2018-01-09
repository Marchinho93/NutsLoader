//
// Created by Marco Bramini on 19/12/17.
//

#ifndef NUTSLOADER_MAINHANDLER_H
#define NUTSLOADER_MAINHANDLER_H

#include "Arduino.h"
#include "Container.h"
#include "Sensor.h"
#include "EventCollector.h"

class MainHandler {
public:
    MainHandler(Container*, Sensor*, EventCollector*);
    void compute();
    int getContainerFillingPercentage(int);
    int containerFillingPercentage;
    int getActualValue();
private:
    void onError();
    int getContainerRange(int, int);
    int getContainerNormalizedActualValue(int, int);
    int getPercentage(double, double);
    Container *container;
    Sensor *sensor;
    EventCollector *eventCollector;
};

#endif //NUTSLOADER_MainHandler_H
