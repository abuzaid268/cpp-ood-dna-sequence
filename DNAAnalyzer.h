//
// Created by abuzaid268 on 2/2/20.
//

#ifndef DNA_SEQUENCE_C___DNAANALYZER_H
#define DNA_SEQUENCE_C___DNAANALYZER_H

#include <ostream>
#include "DNASequence.h"

class DNAAnalyzer{

public:
    template <typename U>
    DNAAnalyzer(U DNA, unsigned int mId, const std::string &mSequenceName);

    DNAAnalyzer(){}
    friend std::ostream &operator<<(std::ostream &os, const DNAAnalyzer &analyzer);

    DNASequence m_sequence;

    const std::string &getMSequenceName() const;

    unsigned int getMId() const;

private:
    unsigned int m_id;
    std::string m_sequenceName;
};

template <typename U>
DNAAnalyzer::DNAAnalyzer(U DNA, unsigned int mId, const std::string &mSequenceName):
    m_sequence(DNA), m_id(mId), m_sequenceName(mSequenceName){}
#endif //DNA_SEQUENCE_C___DNAANALYZER_H
