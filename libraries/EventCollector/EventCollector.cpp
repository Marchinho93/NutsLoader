#include "Arduino.h"
#include "EventCollector.h"
#include "StringList.h"

EventCollector::EventCollector(){
    this->status = 'n';
    this->log = new StringList();
}

void EventCollector::panic(String message) {
    this->log->pushOnTop(String("Panic: " + message));
    this->status = 'p';
}

void EventCollector::fatal(String message) {
    this->log->pushOnTop(String("Fatal: " + message));
    this->status = 'f';
}

void EventCollector::error(String message) {
    this->last = String("Error: " + message);
    this->status = 'e';
}

void EventCollector::warning(String message) {
    this->log->pushOnTop(String("Warning: " + message));
    this->status = 'w';
}

void EventCollector::info(String message) {
    this->log->pushOnTop(String("Info: " + message));
}

void EventCollector::debug(String message) {
    this->log->pushOnTop(String("Debug: " + message));
}

char EventCollector::hasErrors() {
    return this->status;
}

StringList* EventCollector::getLog() {
    return this->log;
}

String EventCollector::getLast() {
    return this->last;
}

void EventCollector::reset() {
    this->status = 'n';
}