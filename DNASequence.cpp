//
// Created by abuzaid268 on 1/18/20.
//

#include "DNASequence.h"
#include "DNAExceptions.h"
#include "Encryption.h"
#include <iostream>
#include <sstream>
#define first (unsigned char) 0x03
#define second (unsigned char) 0x0C
#define third (unsigned char) 0x30
#define fourth (unsigned char) 0xC0
const unsigned char nucleotides[] = {'A','G','C','T'};
const unsigned char dict[20] = {0x00,0x00,0x02,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03};
DNASequence::DNASequence(const char *sequence) {

    size_t x = 0;
    x = strlen(sequence);
    m_SequenceLength = x;
    m_ArrayLength = (x % 4 == 0) ? x/4 : x/4 + 1;
    m_ArrayPointer = new unsigned char [m_ArrayLength + 1];
    m_ArrayPointer = Encryption::Compress(m_ArrayPointer,m_SequenceLength,sequence);
    /*for (i = 0 ; i < x; i++) {
        if (CheckSequenceNotValid(sequence[i])) {
                delete[] m_ArrayPointer;
                m_ArrayLength = 0;
                m_ArrayPointer = NULL;
                throw InvalidNucelotide();
        }
        Encryption = Encryption << shift_amount;
        Encryption = Encryption ^ dict[sequence[i] - 'A'];
        j++;
        if (j == 4 || i == x-1){
            m_ArrayPointer[k] = Encryption;
            Encryption = 0x00;
            j = 0;
            k++;
        }
    }
    m_ArrayPointer[m_ArrayLength] = '\0';*/
}

// constructor with string
DNASequence::DNASequence(std::string sequence) {
    unsigned char Encryption = 0x00;
    size_t i,j = 0,k =0;
    size_t x = sequence.size();
    m_SequenceLength = x;
    m_ArrayLength = (x % 4 == 0) ? x/4 : x/4 + 1;
    m_ArrayPointer = new unsigned char [m_ArrayLength + 1];
    m_ArrayPointer = Encryption::Compress(m_ArrayPointer,m_SequenceLength,sequence.c_str());
    /*for (i = 0 ; i < x; i++) {
        if (CheckSequenceNotValid(sequence[i])) {
            delete[] m_ArrayPointer;
            m_ArrayLength = 0;
            m_ArrayPointer = NULL;
            throw InvalidNucelotide();
        }
        Encryption = Encryption << 2;
        Encryption = Encryption ^ dict[sequence[i] - 'A'];
        j++;
        if (j == 4 || i == x-1){
            m_ArrayPointer[k] = Encryption;
            Encryption = 0x00;
            j = 0;
            k++;
        }
    }
    m_ArrayPointer[m_ArrayLength] = '\0';*/
}

std::ostream &operator<<(std::ostream &os, const DNASequence &sequence) {
    return os << Encryption::DeCompress(sequence.m_ArrayPointer,sequence.m_SequenceLength,sequence.m_ArrayLength);
}
// copy constructor
DNASequence::DNASequence(const DNASequence &src) {
    size_t i,x;
    m_ArrayLength = src.m_ArrayLength;
    m_SequenceLength = src.m_SequenceLength;
    x = m_ArrayLength;
    m_ArrayPointer = new unsigned char[m_ArrayLength + 1];
    unsigned char *ptr_this = m_ArrayPointer,*ptr_that = src.m_ArrayPointer;
    for (i = 0 ; i < x; i++){
        ptr_this[i] = ptr_that[i];
    }
    m_ArrayPointer[x] = '\0';
}
// destructor
DNASequence::~DNASequence() {
        delete [] m_ArrayPointer;
}

// == operator
bool operator==(const DNASequence &lhs,const DNASequence &rhs){
    return !strcmp((const char*)lhs.m_ArrayPointer,
                   (const char*)(rhs.m_ArrayPointer));
}
// != operator
bool operator!=(const DNASequence &lhs,const DNASequence &rhs){
    return strcmp((const char*)lhs.m_ArrayPointer,
                  (const char*)(rhs.m_ArrayPointer));
}
// = overload
DNASequence &DNASequence::operator =(const DNASequence & src) {
    size_t i,x;
    m_ArrayLength = src.m_ArrayLength;
    m_SequenceLength = src.m_SequenceLength;
    x = m_ArrayLength;
    m_ArrayPointer = new unsigned char[m_ArrayLength + 1];
    unsigned char *ptr_this = m_ArrayPointer,*ptr_that = src.m_ArrayPointer;
    for (i = 0 ; i < x; i++){
        ptr_this[i] = ptr_that[i];
    }
    m_ArrayPointer[x] = '\0';
    return *this;
}


DNASequence &DNASequence::operator=(const char * sequence) {
        DNASequence s1(sequence);
        *this = s1;
        return *this;
}

DNASequence &DNASequence::operator=(const std::string& sequence) {
        DNASequence s1(sequence);
        *this = s1;
        return *this;
}
DNASequence DNASequence::replace(char nucleotide, int index) {
        std::string sequence = getString();
        if (index > sequence.size())
            throw InvalidIndex();
        sequence[index] = nucleotide;
        *this = sequence;
        return *this;
}

unsigned char DNASequence::operator[](size_t index) const {
    unsigned char t;
    size_t position;
    size_t indx = index/4;
    if (index >= m_SequenceLength)
        throw InvalidIndex();
    position = index - (indx * 4);
    if (index < ((m_SequenceLength/4) * 4)) {
        t = m_ArrayPointer[index/4];
    }
    else{
        size_t x = m_SequenceLength - ((m_SequenceLength/4)*4);
        size_t shift_amount = 4 - x;
        t = m_ArrayPointer[index/4] << (unsigned char)(2*shift_amount);

    }
    if (position == 0){
        t = t & fourth;
        t = t >> (unsigned char)0x06;
        return nucleotides[t];
    }
    else if (position == 1){
        t = t & third;
        t = t >> (unsigned char)0x04;
        return nucleotides[t];
    }
    else if (position == 2){
        t = t & second;
        t = t >> (unsigned char)0x02;
        return nucleotides[t];
    }
    else{
        t = t & first;
        return nucleotides[t];
    }
    /*std::string x = getString();
    return x[index];*/
}


size_t DNASequence::getSequenceLength() const {
    return m_SequenceLength;
}

DNASequence DNASequence::getPair() const {
    DNASequence x = *this;
    size_t len = x.m_ArrayLength;
    for (size_t i = 0; i < len; i++)
        x.m_ArrayPointer[i] = ~x.m_ArrayPointer[i];
    return x;
}

DNASequence DNASequence::getSliced(int begin, int end)const {
    std::string x;
    if (begin > m_SequenceLength || end > m_SequenceLength)
        throw InvalidIndex();
    for (int i = begin; i < end; i++ ){
     x += (*this)[i];
    }
    DNASequence ret(x);
    return ret;
}

int DNASequence::find(std::string target, int starting_point) const{

    std::string str =  this->getString();
    int x = str.find(target,starting_point);
    return x;
 }

std::vector<int> DNASequence::findAll(std::string target) const{
    std::vector<int> return_vector;
     int result = 0,index = -1;
     std::ostringstream stream;
    stream << *this;
    std::string str =  stream.str();
    while(result != -1){
        index = str.find(target,index + 1);
        result = index;
        if (index >= 0)
            return_vector.push_back(index);

    }
    return return_vector;
}
std::vector<int> DNASequence::findAllCodons(std::string target) const{
    std::vector<int> return_vector;
    int result = 0,index = -1;
    std::ostringstream stream;
    stream << *this;
    std::string str =  stream.str();
    while(result != -1){
        index = str.find(target,index + 1);
        result = index;
        if (index >= 0 && index % 3 == 0)
            return_vector.push_back(index);

    }
    return return_vector;
}

int DNASequence::Count(std::string target) const{
    int index = -1, result = 0, count = 0;
    std::ostringstream stream;
    stream << *this;
    std::string str =  stream.str();
    while(result != -1){
        index = str.find(target,index + 1);
        result = index;
        if (index >= 0)
            count++;
    }
    return count;
}

std::vector<std::string> DNASequence::FindConsensus() const {
     int beginning = 0,end,TAGindex = 0,TAAindex = 0,TGAindex = 0;
     std::string output,original = this->getString();
     std::vector<std::string> output_vector;
     std::vector<int> ATG = findAllCodons("ATG");
     std::vector<int> TAA = findAllCodons("TAA");
     std::vector<int> TAG = findAllCodons("TAG");
     std::vector<int> TGA = findAllCodons("TGA");
    for(int i = 0; i < ATG.size(); i++){
        beginning = ATG[i];
        end = 0;
        for(int x = 0; x < TAG.size(); x++){
            if (TAG[x] > beginning){
                TAGindex = TAG[x];
                break;
            }else TAGindex = 0;
        }
        for(int y = 0; y < TAA.size(); y++){
            if (TAA[y] > beginning){
                TAAindex = TAA[y];
                break;
            } else TAAindex = 0;
        }
        for(int z = 0; z < TGA.size(); z++){
            if(TGA[z] > beginning){
                TGAindex = TGA[z];
                break;
            } else TGAindex = 0;
        }
        if (TGAindex > beginning){
            end = std::max(TGAindex,0);
        }
        if (TAAindex > beginning){
            if (TGAindex > beginning)
                std::min(end,TGAindex);
            else
            end = std::max(0,TAAindex);
        }
        if (TAGindex > beginning){
            if (TGAindex > beginning){
                end = std::min(end,TAGindex);
                if(TAAindex > beginning)
                    end = std::min(TAAindex,end);
            }
            else if (TAAindex > beginning)
                end = std::min(TAAindex,TAGindex);
            else
                end = std::max(TAGindex,0);
        }
        if (end > beginning)
            output_vector.push_back(getSlicedString(beginning,end + 3));
    }

     /*std::cout << "ATG indexes are :" << std::endl;
     for(int i = 0; i < ATG.size(); i++){
         std::cout << ATG[i] << " " << std::endl;
     }
     std::cout << "TAA indexes are :" << std::endl;
     for(int i = 0; i < TAA.size(); i++){
         std::cout << TAA[i] << " " << std::endl;
     }
     std::cout << "TAG indexes are :" << std::endl;
     for(int i = 0; i < TAG.size(); i++){
         std::cout << TAG[i] << " " << std::endl;
     }
     std::cout << "TGA indexes are :" << std::endl;
     for(int i = 0; i < TGA.size(); i++){
         std::cout << TGA[i] << " " << std::endl;
     }*/


//     for (size_t i = 0; i < beginning_sequence.size(); i++){
//         if ((beginning_sequence[i]) % 3 != 0)
//             continue;
//         else {
//             beginning = beginning_sequence[i];
//             if (beginning < 0)
//                 return output_vector;
//             end = this->find("TAG",beginning+3);
//             std::cout << end << std::endl;
//             if (end >= 0 && end % 3 == 0 ) {
//                 std::cout << "Here1" << std::endl;
//                 output = original.substr(beginning, end + 3);
//                 std::cout << output << std::endl;
//                 output_vector.push_back(output);
//                 std::cout << "found this at position " << beginning << " to " << end << std::endl;
//                 continue;
//             }
//             end = this->find("TAA",beginning+3);
//             if (end >= 0 && end % 3 == 0 ) {
//                 std::cout << "Here2" << std::endl;
//                 output = original.substr(beginning, end - 3);
//                 std::cout << output << std::endl;
//                 output_vector.push_back(output);
//                 std::cout << "found this at position " << beginning << " to " << end << std::endl;
//                 continue;
//             }
//             end = this->find("TGA",beginning+3);
//             if (end >= 0 && end % 3 == 0 ) {
//                 std::cout << "Here3" << std::endl;
//                 output = original.substr(beginning, end + 3);
//                 std::cout << output << std::endl;
//                 output_vector.push_back(output);
//                 std::cout << "found this at position " << beginning << " to " << end << std::endl;
//                 continue;
//             }
//             std::cout << "did not find anything for " << beginning << " and " << end << std::endl;
//         }
//     }
    return output_vector;
}

std::string DNASequence::getString() const{
    std::ostringstream stream;
    stream << *this;
    std::string str =  stream.str();
    return str;
}

std::string DNASequence::getSlicedString(int begin, int end) const {
    std::string x;
    if (begin > m_SequenceLength || end > m_SequenceLength)
        throw InvalidIndex();
    for (int i = begin; i < end; i++ ){
        x += (*this)[i];
    }
    return x;
}

DNASequence DNASequence::operator+(DNASequence &other) {
    std::string this_string =getString();
    std::string other_string =other.getString();
    DNASequence x(this_string + other_string);
    return x;
}
