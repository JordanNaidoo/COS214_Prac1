#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <vector>

class Caretaker {
    public:
        Caretaker();
        ~Caretaker();
        void storeMemento(Memento* mem);
        Memento* retrieveMemento();

    private:
        std::vector<Memento*> store;
};

#endif
