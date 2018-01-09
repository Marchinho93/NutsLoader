#include "Arduino.h"
#include "StringList.h"

StringList::StringList() {
    this->head = this;
    this->next = NULL;
}

StringList::StringList(String data, StringList* head) {
    this->data = data;
    this->head = head;
    this->next = NULL;
}

void StringList::pushOnTop(String data) {
    StringList newEntry = StringList(data, this->head);
    this->head =&newEntry;
    newEntry.next = this;
}