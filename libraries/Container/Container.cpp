//
// Created by Marco Bramini on 19/12/17.
//

#include "Arduino.h"
#include "Container.h"

Container::Container(int minHeight, int maxHeight, int minThreshold, int maxThreshold) {
    this->minHeight = minHeight;
    this->maxHeight = maxHeight;
    this->minThreshold = minThreshold;
    this->maxThreshold = maxThreshold;
}
