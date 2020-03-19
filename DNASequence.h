//
// Created by abuzaid268 on 1/18/20.
//

#ifndef DNA_SEQUENCE_C___DNASEQUENCE_H
#define DNA_SEQUENCE_C___DNASEQUENCE_H

#include <cstring>
#include <string>
#include <ostream>
#include <map>
#include <vector>
#include "DnaInterface.h"
extern const unsigned char nucleotides[4];
extern const unsigned char dict[20];
/*extern std::map<unsigned char, unsigned char> dict;*/
class DNASequence: public DnaInterface{
public:
    explicit DNASequence(const char* sequence);

    explicit DNASequence(std::string sequence);

    DNASequence(){};

    DNASequence(const DNASequence&);

    ~DNASequence();

    friend std::ostream &operator<<(std::ostream &os, const DNASequence &sequence);

    friend bool operator==(const DNASequence &lhs, const DNASequence &rhs) ;
    friend bool operator!=(const DNASequence &lhs, const DNASequence &rhs) ;
// operator == should not be used in the public
    DNASequence& operator =(const DNASequence&);

    unsigned char operator [](size_t index) const;

    DNASequence& operator =(const char*);

    DNASequence& operator =(const std::string&);

    size_t getSequenceLength() const;

    DNASequence getPair() const;

    DNASequence getSliced(int begin, int end)const;

    int find(std::string target, int starting_point = 0)const;

    std::vector<int> findAll(std::string target)const;

    int Count(std::string target)const;

    std::vector<std::string> FindConsensus()const;

    std::vector<int> findAllCodons(std::string target) const;

    std::string getSlicedString(int begin, int end)const;

    std::string getString() const;

    DNASequence replace(char nucleotide, int index);

    DNASequence operator+(DNASequence& other);

private:
    size_t m_ArrayLength;
    size_t m_SequenceLength;
    unsigned char *m_ArrayPointer;

};

inline bool CheckSequenceNotValid(char x);

char ReturnPair(char x);

#endif //DNA_SEQUENCE_C___DNASEQUENCE_H
