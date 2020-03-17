//
// Created by abuzaid268 on 3/16/20.
//

#include "CommandHelper.h"
const char * Naming[5] = {"_","_s","_r","_c","_p"};
std::string CommandHelper::CheckIfNameExists(string CheckIfSequenceNameExists, map<string, DNAAnalyzer *> &MapOfNames,
                                             NamingConvention naming) {
    std::ostringstream stm ;
    std::string defaultname = CheckIfSequenceNameExists;
    int NumberOfChecks = 0;
    while(MapOfNames[CheckIfSequenceNameExists]){
        stm.str("");
        stm.clear();
        stm << Naming[naming] << ++NumberOfChecks;
        CheckIfSequenceNameExists = defaultname + stm.str();
    }
    return CheckIfSequenceNameExists;
}

int CommandHelper::ChangeStringtoInt(string &number) {
    std::stringstream from_str(number);
    int to_int;
    from_str >> to_int;
    return to_int;
}

char CommandHelper::ChangeStringtoChar(string &nuc) {
    std::stringstream from_str(nuc);
    char to_char;
    from_str >> to_char;
    return to_char;
}

DNAAnalyzer *
CommandHelper::getProperElement(map<string, DNAAnalyzer *> &MapOfNames, map<int, DNAAnalyzer *> &MapOfIDs, int ID_int,
                                const string &name) {
    DNAAnalyzer* AnalyzerPtrSrc;
    if (MapOfIDs[ID_int]){
        AnalyzerPtrSrc = MapOfIDs[ID_int];
    }
    else if (MapOfNames[CommandHelper::stripName(name)]){
        AnalyzerPtrSrc = MapOfNames[CommandHelper::stripName(name)];
    } else{
        throw InvalidSequenceName();
    }
    return AnalyzerPtrSrc;
}

string CommandHelper::getStripedID(string src) {
    string input_id;
    for (int i = 0; i < src.length(); i++){
        if (src[i] != '#')
            input_id += src[i];
    }
    return input_id;
}

void CommandHelper::updateMaps(DNAAnalyzer *AnalyzerPtr, map<string, DNAAnalyzer *> &MapOfNames,
                               map<int, DNAAnalyzer *> &MapOfIDs, const string &nameOfSequence) {
    MapOfNames[nameOfSequence] = AnalyzerPtr;
    MapOfIDs[AnalyzerPtr->getMId()] = AnalyzerPtr;
}

bool CommandHelper::CheckSequenceNotValid(char nucleotide) {
    return !(nucleotide == 'T' or nucleotide == 'A' or nucleotide == 'C' or nucleotide == 'G' );
}

string CommandHelper::toUpper(string &src) {
    for (int i = 0; i < src.size(); i++)
        if (src[i] <= 122 && src[i] >= 97) {
            src[i] -= 32;
        }
    return src;
}

string CommandHelper::stripName(string name) {
        string strippedName;
        if (name[0] == '@')
            strippedName = name.substr(1,name.size());
        else
            throw InvalidInputStyle();
        return strippedName;
}

bool CommandHelper::changeSeqName(const string &new_name,const string &old_name, map<string, DNAAnalyzer *> &MapOfNames) {
    if(MapOfNames[new_name])
        return false;
    else{
        map<string, DNAAnalyzer *>::iterator it = MapOfNames.find(old_name);
        DNAAnalyzer* temp = MapOfNames[old_name];
        MapOfNames.erase(it);
        MapOfNames[new_name] = temp;
        MapOfNames[new_name]->changeName(new_name);
        /*MapOfNames[old_name] = NULL;
        MapOfNames.swap()*/
        /*MapOfNames[old_name]->changeName(new_name);*/

        return true;
    }
}
