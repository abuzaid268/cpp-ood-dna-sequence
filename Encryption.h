//
// Created by abuzaid268 on 2/4/20.
//

#ifndef DNA_SEQUENCE_C___ENCRYPTION_H
#define DNA_SEQUENCE_C___ENCRYPTION_H

#include <cstddef>
#include <string>
struct Encryption{
    static unsigned char * Compress(unsigned char * Array,size_t string_length,const char *sequence);
    static std::string DeCompress(unsigned char *Array, size_t sequence_length, size_t string_length);
};
#endif //DNA_SEQUENCE_C___ENCRYPTION_H
