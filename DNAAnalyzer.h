//
// Created by abuzaid268 on 2/2/20.
//

#ifndef DNA_SEQUENCE_C___DNAANALYZER_H
#define DNA_SEQUENCE_C___DNAANALYZER_H

#include <ostream>
#include "DNASequence.h"
class DNAAnalyzer: public DnaInterface{
public:
    template <typename U>
    DNAAnalyzer(U DNA, unsigned int mId, const std::string &mSequenceName);

    DNAAnalyzer(){}

    friend std::ostream &operator<<(std::ostream &os, const DNAAnalyzer &analyzer);

    const std::string &getMSequenceName() const;

    unsigned int getMId() const;

    void changeName(std::string new_name);

    friend bool operator==(const DNAAnalyzer &lhs, const DNAAnalyzer &rhs) ;

    friend bool operator!=(const DNAAnalyzer &lhs, const DNAAnalyzer &rhs) ;

    unsigned char operator [](size_t index) const;

    DNAAnalyzer& operator =(const char*);

    DNAAnalyzer& operator =(const std::string&);

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

    DNAAnalyzer operator+(DNAAnalyzer& other);

    DNASequence& getSequence();

private:
    DNAAnalyzer& operator =(const DNAAnalyzer&){
        return *this;
    }
    unsigned int m_id;
    std::string m_sequenceName;
    DNASequence* m_sequence;
};

template <typename U>
DNAAnalyzer::DNAAnalyzer(U DNA, unsigned int mId, const std::string &mSequenceName):
     m_id(mId), m_sequenceName(mSequenceName){
         m_sequence = new DNASequence(DNA);
    }



/*DNAAnalyzer &DNAAnalyzer::operator=(const DNAAnalyzer &) {
    return <#initializer#>;
}*/

#endif //DNA_SEQUENCE_C___DNAANALYZER_H
