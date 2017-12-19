//
// Created by Marco Bramini on 19/12/17.
//

#include "Arduino.h"
#include "Loader.h"

Loader::Loader(int pin) {
    this->pin = pin;
    pinMode(this->pin, OUTPUT);
}

void Loader::start() {
    digitalWrite(this->pin, HIGH);
    this->isLoading = true;
}

void Loader::stop() {
    digitalWrite(this->pin, LOW);
    this->isLoading = false;
}
