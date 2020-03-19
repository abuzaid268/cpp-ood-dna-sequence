//
// Created by abuzaid268 on 3/18/20.
//

#ifndef DNA_SEQUENCE_C___DNAINTERFACE_H
#define DNA_SEQUENCE_C___DNAINTERFACE_H
#include <cstddef>
#include <vector>
#include <string>
class DNASequence;
class DnaInterface{

    virtual size_t getSequenceLength() const = 0;

    virtual DNASequence getPair() const = 0;

    virtual DNASequence getSliced(int begin, int end)const = 0;

    virtual int find(std::string target, int starting_point = 0) const = 0;

    virtual std::vector<int> findAll(std::string target)const = 0;

    virtual int Count(std::string target)const = 0;

    virtual std::vector<std::string> FindConsensus()const = 0;

    virtual std::vector<int> findAllCodons(std::string target) const = 0;

    virtual std::string getSlicedString(int begin, int end)const = 0;

    virtual std::string getString() const = 0;

    virtual DNASequence replace(char nucleotide, int index) = 0;

};
#endif //DNA_SEQUENCE_C___DNAINTERFACE_H
