//
// Created by abuzaid268 on 2/1/20.
//

#ifndef DNA_SEQUENCE_C___FILES_PROCESSING_H
#define DNA_SEQUENCE_C___FILES_PROCESSING_H

#include "DNASequence.h"
#include <fstream>
class file_processing{
public:

    static std::string readFile(const char * filename);

    static void writeFile(const char * filename, std::string);

};
#endif //DNA_SEQUENCE_C___FILES_PROCESSING_H
