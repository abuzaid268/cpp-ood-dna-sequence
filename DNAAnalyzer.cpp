//
// Created by abuzaid268 on 2/2/20.
//

#include <iostream>
#include "DNAAnalyzer.h"

/*DNAAnalyzer::DNAAnalyzer(const std::string &sequence, unsigned int mId, const std::string &mSequenceName) : m_sequence(
        sequence), m_id(mId), m_sequenceName(mSequenceName) {}*/

std::ostream &operator<<(std::ostream &os, const DNAAnalyzer &analyzer) {
    os << '[' << analyzer.m_id << "] " << analyzer.m_sequenceName << ": ";/* << analyzer.m_sequence;*/
    size_t sequence_length = analyzer.m_sequence->getSequenceLength();
    if (sequence_length >= 40){
        os <<  analyzer.m_sequence->getSlicedString(0,32);
        os << "...";
        os << analyzer.m_sequence->getSlicedString((int)sequence_length-3, sequence_length);
    }
    else
        os << *analyzer.m_sequence;
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

unsigned char DNAAnalyzer::operator[](size_t index) const {
    return (*m_sequence)[index];
}
size_t DNAAnalyzer::getSequenceLength() const {
    return m_sequence->getSequenceLength();
}

DNASequence DNAAnalyzer::getPair() const {
    DNASequence dna(m_sequence->getPair());
    return dna;
}

DNASequence DNAAnalyzer::getSliced(int begin, int end) const {
    return m_sequence->getSliced(begin, end);
}

int DNAAnalyzer::find(std::string target, int starting_point) const {
    return m_sequence->find(target,starting_point);
}

std::vector<int> DNAAnalyzer::findAll(std::string target) const {
    return m_sequence->findAll(target);
}

int DNAAnalyzer::Count(std::string target) const {
    return m_sequence->Count(target);
}

std::vector<std::string> DNAAnalyzer::FindConsensus() const {
    return m_sequence->FindConsensus();
}

std::vector<int> DNAAnalyzer::findAllCodons(std::string target) const {
    return m_sequence->findAllCodons(target);
}

std::string DNAAnalyzer::getSlicedString(int begin, int end) const {
    return m_sequence->getSlicedString(begin, end);
}

std::string DNAAnalyzer::getString() const {
    return m_sequence->getString();
}

DNASequence DNAAnalyzer::replace(char nucleotide, int index) {
    return m_sequence->replace(nucleotide, index);
}

bool operator==(const DNAAnalyzer &lhs, const DNAAnalyzer &rhs) {
    return *(lhs.m_sequence) == *(rhs.m_sequence);
}

bool operator!=(const DNAAnalyzer &lhs, const DNAAnalyzer &rhs) {
    return *(lhs.m_sequence) != *(rhs.m_sequence);
}

DNAAnalyzer &DNAAnalyzer::operator=(const char *dna) {
    *(m_sequence) = dna;
    return *this;
}

DNAAnalyzer &DNAAnalyzer::operator=(const std::string &dna) {
    *(m_sequence) = dna;
    return *this;
}

DNAAnalyzer DNAAnalyzer::operator+(DNAAnalyzer &other) {

    return DNAAnalyzer();
}

DNASequence& DNAAnalyzer::getSequence() {
    return *m_sequence;
}
