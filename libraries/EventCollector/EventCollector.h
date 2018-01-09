//
// Created by Marco Bramini on 26/12/17.
//
// Event collector
// Throws events and log them.
// 

#ifndef NUTSLOADER_EVENTCOLLECTOR_H
#define NUTSLOADER_EVENTCOLLECTOR_H

#include "Arduino.h"

class EventCollector {
public:
    EventCollector();
    void panic(String);
    void error(String);
    void info(String);
    void debug(String);
    char hasErrors()
private:
    char status;
    StringList log;
};

#endif //NUTSLOADER_EVENTCOLLECTOR_H
