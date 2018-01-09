//
// Created by Marco Bramini on 26/12/17.
//
// Event collector
// Throws events and log them.
// 

#ifndef NUTSLOADER_EVENTCOLLECTOR_H
#define NUTSLOADER_EVENTCOLLECTOR_H

#include "Arduino.h"
#include "StringList.h"

class EventCollector {
public:
    EventCollector();
    void panic(String);
    void fatal(String);
    void error(String);
    void warning(String);
    void info(String);
    void debug(String);
    char hasErrors();
    StringList* getLog();
    String getLast();
    void reset();
private:
    char status;
    String last;
    StringList* log;
};

#endif //NUTSLOADER_EVENTCOLLECTOR_H
