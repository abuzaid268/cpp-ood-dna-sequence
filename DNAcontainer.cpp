//
// Created by abuzaid268 on 2/2/20.
//

#include "DNAcontainer.h"
DNAContainer* DNAContainer::instance = 0;
int DNAContainer::seq_ID = 0;
DNAContainer *DNAContainer::getInstance() {
    if (instance == 0)
        instance = new DNAContainer();
    return instance;
}

map<string, DNAAnalyzer *> &DNAContainer::getMapOfNames() {
    return DNAList_by_name;
}

map<int, DNAAnalyzer *> &DNAContainer::getMapOfIDs() {
    return DNAList_by_ID;
}

int& DNAContainer::getID() {
    return seq_ID;
}
