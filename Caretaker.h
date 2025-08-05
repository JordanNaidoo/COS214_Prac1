#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"

class Caretaker {
    public:
        Caretaker() {}
        void storeMemento(Memento mem) {
            this->mem= mem;
        }
        Memento retrieveMemento() {
            return mem;
        }

    private:
        Memento mem;
};

#endif
