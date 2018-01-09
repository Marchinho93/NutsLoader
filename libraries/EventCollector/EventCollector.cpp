#include "Arduino.h"
#include "EventCollector.h"

EventCollector::EventCollector(){
    this->status = 'n';
    this->log = new StringList().getHead();
}

void::panic(String message) {
    this->log.pushOnTop(strcat("Panic: ", message));
    this->status = 'p';
}

void::fatal(String message) {
    this->log.pushOnTop(strcat("Fatal: ", message));
    this->status = 'f';
}

void:error(String message) {
    this->log.pushOnTop(strcat("Error: ", message));
    this->status = 'e';
}

void:warning(String message) {
    this->log.pushOnTop(strcat("Warning: ", message));
    this->status = 'w';
}

void::info(String message) {
    this->log.pushOnTop(strcat("Info: ", message));
}

void debug(String message) {
    this->log.pushOnTop(strcat("Debug: ", message));
}

char hasErrors() {
    return this->status;
}