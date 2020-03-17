//
// Created by abuzaid268 on 2/2/20.
//

#include <iostream>
#include "DNAAnalyzer.h"

/*DNAAnalyzer::DNAAnalyzer(const std::string &sequence, unsigned int mId, const std::string &mSequenceName) : m_sequence(
        sequence), m_id(mId), m_sequenceName(mSequenceName) {}*/

std::ostream &operator<<(std::ostream &os, const DNAAnalyzer &analyzer) {
    os << '[' << analyzer.m_id << "] " << analyzer.m_sequenceName << ": ";/* << analyzer.m_sequence;*/
    size_t sequence_length = analyzer.m_sequence.getSequenceLength();
    if (sequence_length >= 40){
        os <<  analyzer.m_sequence.getSlicedString(0,32);
        os << "...";
        os << analyzer.m_sequence.getSlicedString((int)sequence_length-3, sequence_length);
    }
    else
        os << analyzer.m_sequence;
    return os;
}

const std::string &DNAAnalyzer::getMSequenceName() const {
    return m_sequenceName;
}

unsigned int DNAAnalyzer::getMId() const {
    return m_id;
}

void DNAAnalyzer::changeName(std::string new_name) {
    m_sequenceName = new_name;
}

