//
// Created by abuzaid268 on 2/2/20.
//

#ifndef DNA_SEQUENCE_C___FACTORY_H
#define DNA_SEQUENCE_C___FACTORY_H
#include "command.h"
struct factory{
    static command* method(vector<string>&);
    static void delete_ptrs();
};
#endif //DNA_SEQUENCE_C___FACTORY_H
