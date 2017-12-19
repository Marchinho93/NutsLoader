//
// Created by Marco Bramini on 19/12/17.
//

#ifndef NUTSLOADER_LOADER_H
#define NUTSLOADER_LOADER_H

#include "Arduino.h"

class Loader {
public:
    Loader(int);
    void start();
    void stop();
    bool isLoading;
private:
    int pin;
};

#endif //NUTSLOADER_LOADER_H
