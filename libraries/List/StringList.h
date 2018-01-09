//
// Created by Marco Bramini on 26/12/17.
//

#ifndef NUTSLOADER_STRINGLIST_H
#define NUTSLOADER_STRINGLIST_H

#include "Arduino.h"

class StringList {
public:
    StringList();
    void pushOnTop(String);
    String* getHead();
private:
    String data;
    String* head;
    String* next;
};

#endif //NUTSLOADER_STRINGLIST_H
