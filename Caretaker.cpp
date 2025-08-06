#include "Caretaker.h"

Caretaker::Caretaker() {}

Caretaker::~Caretaker() {
    for (Memento* mem : store) delete mem;
    store.clear();
}

void Caretaker::storeMemento(Memento* mem) {
    store.push_back(mem);
}

Memento* Caretaker::retrieveMemento() {
    if (store.empty()) return NULL;
    Memento* mem = store.back();
    store.pop_back();
    return mem;
}
