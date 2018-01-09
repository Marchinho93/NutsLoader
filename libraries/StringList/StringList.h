//
// Created by Marco Bramini on 26/12/17.
//

#ifndef NUTSLOADER_STRINGLIST_H
#define NUTSLOADER_STRINGLIST_H

#include "Arduino.h"

class StringList {
public:
    StringList();
    StringList(String, StringList*);
    void pushOnTop(String);
    String data;
    StringList* head;
    StringList* next;
private:
};

#endif //NUTSLOADER_STRINGLIST_H
