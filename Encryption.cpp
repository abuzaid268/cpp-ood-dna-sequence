//
// Created by abuzaid268 on 2/4/20.
//

#include "Encryption.h"
#include "DNAExceptions.h"
#include "DNASequence.h"
#include <iostream>
bool CheckSequenceNotValid(char nucleotide) {
    return !(nucleotide == 'T' or nucleotide == 'A' or nucleotide == 'C' or nucleotide == 'G' );
}
unsigned char *Encryption::Compress(unsigned char *Array, size_t string_length,const char *sequence) {
    unsigned char Encryption = 0x00,shift_amount = 0x02;
    size_t i,j = 0,k =0;
    for (i = 0 ; i < string_length; i++) {

        if (CheckSequenceNotValid(toupper(sequence[i]))) {
            delete[] Array;
            Array = NULL;
            throw InvalidNucelotide();
        }
        Encryption = Encryption << shift_amount;
        Encryption = Encryption ^ dict[toupper(sequence[i]) - 'A'];
        j++;
        if (j == 4 || i == string_length-1){
            Array[k] = Encryption;
            Encryption = 0;
            j = 0;
            k++;
        }
    }
    Array[k] = '\0';

    
    return Array;
    
}

std::string Encryption::DeCompress(unsigned char *Array, size_t sequence_length, size_t string_length) {
    std::string complete_string;
    std::string out;
    size_t i,j,k = sequence_length;
    unsigned char Display,Decryption,shift_amount = 0x02, And_amount = 0x03;
    for (i = 0; i < string_length;i++){
        Decryption = Array[i];
        for (j = 0; j < 4;j++){
            Display = Decryption & And_amount;
            out.insert(0,1,nucleotides[Display]);
            Decryption = Decryption >> shift_amount;
            k--;
            if (!k)
                break;
        }
        complete_string += out;
        out.clear();
    }

    return complete_string;
}
