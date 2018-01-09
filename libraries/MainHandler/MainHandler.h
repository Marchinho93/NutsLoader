//
// Created by Marco Bramini on 19/12/17.
//

#ifndef NUTSLOADER_LOGICUNIT_H
#define NUTSLOADER_LOGICUNIT_H

#include "Arduino.h"
#include "Container.h"
#include "Sensor.h"
#include "EventCollector.h"

class LogicUnit {
public:
    LogicUnit(Container*, Sensor*, EventCollector*);
    void compute();
    int getContainerFillingPercentage(int);
    int containerFillingPercentage;
    int getActualValue();
private:
    bool isValueInContainerRange(int);
    int getContainerRange(int, int);
    int getContainerNormalizedActualValue(int, int);
    int getPercentage(double, double);
    Container *container;
    Sensor *sensor;
    EventCollector *eventCollector;
};

#endif //NUTSLOADER_LOGICUNIT_H
