//
// Created by Marco Bramini on 19/12/17.
//

#include "LogicUnit.h"
#include "Container.h"

LogicUnit::LogicUnit(Container *container, Sensor *sensor) {
    this->container = container;
    this->sensor = sensor;
}

// compute is the LogicUnit's loop routine.
// return -1 if something goes wrong.
int LogicUnit::compute() {
    int error = 0;
    this->containerFillingPercentage = getContainerFillingPercentage(getActualValue());
    if (this->containerFillingPercentage == -1)
        return -1;
    return error;
}

// getActualValue get the value read by the sensor
// return -1 if the value is out of range.
int LogicUnit::getActualValue() {
    int value = this->sensor->readValue();
    if(!isValueInContainerRange(value))  
        return -1;
    return value;
}

// isValueInContainerRange return true if the value is in the container range, else false.
bool LogicUnit::isValueInContainerRange(int value) {
    if(value < this->container->maxHeight || value > this->container->minHeight)
        return false;
    return true;
}

// getContainerFillingPercentage calculates the normalized percentage value associated
// to a value.
// return -1 if something goes wrong.
int LogicUnit::getContainerFillingPercentage(int actualValue) {
    if(actualValue == -1)
        return -1;
    int range = getContainerRange(this->container->minHeight, this->container->maxHeight);
    int normActualValue = getContainerNormalizedActualValue(actualValue, this->container->maxHeight);
    int percentage = getPercentage(range, range - normActualValue);
    if (percentage<0)
        return -1;
    return percentage;
}

// getContainerRange returns the usable range of a container.
int LogicUnit::getContainerRange(int minHeight, int maxHeight) {
    return minHeight - maxHeight;
}

// getContainerNormalizedActualValue return the normalized actual value
// compared to the container.
int LogicUnit::getContainerNormalizedActualValue(int actualValue, int maxHeight) {
    return actualValue - maxHeight;
}

// getPercentage returns the percentage of a value compared to a max value.
int LogicUnit::getPercentage(double max, double value) {
    return (int)(value*100/max);
}
