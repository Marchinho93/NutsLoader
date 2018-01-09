#include "Arduino.h"

StringList::StringList(String data, String* head) {
    this->data = data;
    this->head = head;
}

void pushOnTop(String data) {
    StringList newEntry = StringList(data, this->head);
    this->head = newEntry;
    newEntry->next = this;
}

String* getHead() {
    return this->head;
}