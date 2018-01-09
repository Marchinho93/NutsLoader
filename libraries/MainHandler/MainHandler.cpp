//
// Created by Marco Bramini on 19/12/17.
//

#include "MainHandler.h"
#include "Container.h"
#include "EventCollector.h"

MainHandler::MainHandler(Container *container, Sensor *sensor, EventCollector *eventCollector) {
    this->container = container;
    this->sensor = sensor;
    this->eventCollector = eventCollector;
}

// compute is the MainHandler's loop routine.
int MainHandler::compute() {
        this->containerFillingPercentage = getContainerFillingPercentage(getActualValue());    
    return error;
}

// onError method indicates the behaviour of the system when an error occurs.
void MainHandler::onError() {
    //TODO: Loader shut down!!!
}

// getActualValue get the value read by the sensor
int MainHandler::getActualValue() {
    int value = this->sensor->readValue();
    if (value < 0 || value > this->container->minHeight || value < this->container->maxHeight)
        this->eventCollector.error("Sensor: Bad Readings");
        onError();
    return value;
}

// getContainerFillingPercentage calculates the normalized percentage value associated
// to a value.
int MainHandler::getContainerFillingPercentage(int actualValue) {
    int range = this->container->containerRange;
    int normActualValue = this->container.getContainerNormalizedActualValue(actualValue);
    int percentage = getPercentage(range, range - normActualValue);
    if (percentage<0 || percentage>100){
        this->eventCollector.error("Container: Filling Percentage Calculation Failed");
        onError()
    }
    return percentage;
}

// getPercentage returns the percentage of a value compared to a max value.
int MainHandler::getPercentage(double max, double value) {
    return (int)(value*100/max);
}
