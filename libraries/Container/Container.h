//
// Created by Marco Bramini on 19/12/17.
//

#ifndef NUTSLOADER_CONTAINER_H
#define NUTSLOADER_CONTAINER_H

#include "Arduino.h"

class Container {
public:
    Container(int, int, int, int);
    int getContainerNormalizedActualValue(int);
    int minHeight, maxHeight, minThreshold, maxThreshold, containerRange;
private:
    
};

#endif //NUTSLOADER_CONTAINER_H
