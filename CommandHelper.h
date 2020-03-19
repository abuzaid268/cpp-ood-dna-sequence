//
// Created by abuzaid268 on 3/16/20.
//

#ifndef DNA_SEQUENCE_C___COMMANDHELPER_H
#define DNA_SEQUENCE_C___COMMANDHELPER_H
#include <string>
#include <vector>
#include "files_processing.h"
#include "DNAcontainer.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include "DNAExceptions.h"
using std::string;
using std::vector;
using std::iterator;
extern const char * Naming[5];
enum NamingConvention {Original,Sliced,Replaced,Concatenated,Paired};
struct CommandHelper{

    static std::string CheckIfNameExists(string CheckIfSequenceNameExists,map<string,DNAAnalyzer*> &MapOfNames, NamingConvention naming );

    static int ChangeStringtoInt(string& number);

    static char ChangeStringtoChar(string& nuc);

    static string stripName(string name);

    static DNAAnalyzer* getProperElement(map<string,DNAAnalyzer*> &MapOfNames,map<int,DNAAnalyzer*> &MapOfIDs, int ID_int, const string& name);

    static string getStripedID(string src);

    static void updateMaps(DNAAnalyzer* AnalyzerPtr, map<string,DNAAnalyzer*> &MapOfNames,map<int,DNAAnalyzer*> &MapOfIDs,const string& nameOfSequence);

    static bool CheckSequenceNotValid(char x);

    static string toUpper(string& src);

    static bool changeSeqName(const string &new_name, const string& old_name,map<string,DNAAnalyzer*> &MapOfNames);

    static void deleteSeq(map<string,DNAAnalyzer*> &MapOfNames,map<int,DNAAnalyzer*> &MapOfIDs, int ID_int, const string& name );
};
#endif //DNA_SEQUENCE_C___COMMANDHELPER_H
