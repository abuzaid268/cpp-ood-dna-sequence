//
// Created by abuzaid268 on 2/2/20.
//

/*#include <iostream>
#include "DNASequence.h"
#include "DNAExceptions.h"
using namespace std;
int main() {
    DNASequence S1("CATATGCGAAGCTACCGATGAGGC");
    std::string s1 = "CGATTA";
    DNASequence S2(s1);
    DNASequence S3 = S2;
    cout << S3 << endl;
    S3 = "AGACATTAG";
    cout << S3 << endl;
    S3 = s1;
    cout << S2 << endl;
    cout << S1 << endl;
    S2 = S1;
    cout << S2 << endl;
    cout << S3 << endl;
    cout << (S2==S1) << endl;
    cout << S1 << endl;
    cout << S1.getPair() << endl;
    cout << S1 << endl;
    cout << S1.getSliced(3,8) << endl;
    cout << S1.find("TCT") << endl;
    std::vector<int> x = S1.findAll("AT");
    for (int i = 0; i <(int) x.size(); i++){
        cout << x[i] << " ";
    }
    cout << endl;
    cout << S1.Count("AT") << endl;
    cout << S1.FindConsensus();
    return 0;
}*/
/*
#include "DNASequence.h"
#include "DNAExceptions.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
TEST(DNASequence, InvalidSequence1)
{
    DNASequence S3("A");
    try {
        DNASequence S3("ATATGCKATCGA");
    }
    catch(InvalidNucelotide& e) {
        cout << "Caught Invalid Nucleotide Exception" << endl;
        cout << e.what() << endl;
    }
}
TEST(DNASequence, InvalidSequenc2)
{
    DNASequence S3("A");
    try {
        string s1 = "ATATGCKATCGA";
        S3 = s1;
    }
    catch(InvalidNucelotide& e) {
        cout << "Caught Invalid Nucleotide Exception" << endl;
        cout << e.what() << endl;
    }
    cout << S3.getPair();
}
TEST(DNASequence, AssignmentOperator)
{   DNASequence S1("TTAGCTAGGCATATGGCGCGCTACAACTGATGCA");
    string ss1 = "AGCTAGAGCAGCAGCTAGCATGCATGGCATCGATGTCAGAT";
    DNASequence S2(ss1);
    DNASequence S3("A");
    S3 = S1;
    ASSERT_TRUE(S3 == S1);
    ASSERT_TRUE(S3.getSequenceLength() == S1.getSequenceLength());
}
TEST(DNASequence, CopyConstructor)
{
    DNASequence S1("TTAGCTAGGCATATGGCGCGCTACAACTGATGCA");
    string ss1 = "AGCTAGAGCAGCAGCTAGCATGCATGGCATCGATGTCAGAT";
    DNASequence S2(ss1);
    DNASequence S3("A");
    //DNASequence S3("TATAGAGACACA");
    S3 = S1;
    ASSERT_TRUE(S3 == S1);
    ASSERT_TRUE(S3.getSequenceLength() == S1.getSequenceLength());
}/*
TEST(DNASequence, AssignmentfromCString)
{
    DNASequence S3("A");
    //DNASequence S3("");
    S3 = "AGACATAT";
    ASSERT_FALSE(strcmp(S3.m_ArrayPointer,"AGACATAT"));
}*//*
TEST(DNASequence, Equality)
{   DNASequence S1("TTAGCTAGGCATATGGCGCGCTACAACTGATGCA");
    string ss1 = "AGCTAGAGCAGCAGCTAGCATGCATGGCATCGATGTCAGAT";
    DNASequence S2(ss1);
    DNASequence S3("A");
    S3 = S2;
    ASSERT_FALSE(S1 == S2);
    ASSERT_TRUE(S1 != S2);
    cout << "S1 is : " << S1;
    cout << "S2 is : " << S2;
    cout << "S3 is : " << S3;
    cout << (S1 == S2) << endl;
    ASSERT_TRUE(S3 == S2);
    ASSERT_FALSE(S3 != S2);

}
TEST(DNASequence, Indexing)
{
    DNASequence S3("A");
    string s1 = "TATATAGAGACACCTTGGGGGGGCA";
    S3 = s1;
    for (size_t i = 0; i < S3.getSequenceLength(); i++)
        ASSERT_EQ(S3[i],s1[i]);
}
TEST(DNASequence, latest)
{
    DNASequence S1("CATATGCGAAGCTACCGATGAGGC");
    std::string s1 = "CGATTA";
    DNASequence S2(s1);
    DNASequence S3 = S2;
    cout <<"pair of "<<S1 << " is "<< endl<< S1.getPair()<<endl;
    cout << "S1 sliced is " << S1.getSliced(3,8) << endl;
    cout << "found string GAAG in index " << S1.find("GAAG") << endl;
    std::vector<int> x = S1.findAll("AT");
    cout << "AT found in the following indexes in the sequence" << endl;
    for (int i = 0; i <(int) x.size(); i++){
        cout << x[i] << " ";
    }
    cout << endl;
    cout << "number of AT in the sequence : " << S1.Count("AT") << endl;
    cout << "the consensus in the series is "<<S1.FindConsensus() << endl;
}*/