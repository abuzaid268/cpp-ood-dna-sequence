//
// Created by abuzaid268 on 2/2/20.
//

#ifndef DNA_SEQUENCE_C___DNACONTAINER_H
#define DNA_SEQUENCE_C___DNACONTAINER_H
#include "DNAAnalyzer.h"
#include <map>
#include <string>
using std::map;
using std::string ;
struct DNAContainer{
    static DNAContainer * getInstance();
    map<string ,DNAAnalyzer *>& getMapOfNames();
    map<int, DNAAnalyzer *> &getMapOfIDs();
    static int& getID();
private:
    DNAContainer(){}
    static DNAContainer* instance;
    map<string,DNAAnalyzer *> DNAList_by_name;
    map<int,DNAAnalyzer *> DNAList_by_ID;
    static int seq_ID;
};
#endif //DNA_SEQUENCE_C___DNACONTAINER_H
