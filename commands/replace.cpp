//
// Created by abuzaid268 on 3/16/20.
//

#include "../command.h"



void replace_cmd::execute(vector<string> command_to_execute) {

    DNAAnalyzer* AnalyzerPtrDst;
    DNAAnalyzer* AnalyzerPtrSrc;
    DNAContainer* container = DNAContainer::getInstance();
    map<string,DNAAnalyzer*> &MapOfNames = container->getMapOfNames();
    map<int, DNAAnalyzer *> &MapOfIDs = container->getMapOfIDs();
    int &id = DNAContainer::getID();
    string nameOfSequence;
    string input_id = CommandHelper::getStripedID(command_to_execute[1]);

    int ID_int = CommandHelper::ChangeStringtoInt(input_id);;
    AnalyzerPtrSrc = CommandHelper::getProperElement(MapOfNames,MapOfIDs,ID_int,command_to_execute[1]);

    int index;
    int Replacing_end;
    int Replacing_begin;
    char nucleotide;
    int command_size = command_to_execute.size();
    if (command_to_execute[command_size - 2 ] == ":"){
        if (command_to_execute[command_size - 1] == "@@"){
            nameOfSequence = AnalyzerPtrSrc->getMSequenceName();
            nameOfSequence = CommandHelper::CheckIfNameExists(nameOfSequence,MapOfNames,Replaced);
        }
        else {
            nameOfSequence = CommandHelper::stripName(command_to_execute[5]);
            nameOfSequence = CommandHelper::CheckIfNameExists(nameOfSequence,MapOfNames,Original);
        }
        Replacing_end = command_size - 3 ;
        Replacing_begin = 2;
        AnalyzerPtrDst = new DNAAnalyzer(AnalyzerPtrSrc->m_sequence.getString(),++id,nameOfSequence);
    }
    else if (command_to_execute[command_size - 2 ] != ":"){
        Replacing_end = command_size - 1;
        Replacing_begin = 2;
        AnalyzerPtrDst = AnalyzerPtrSrc;
    }
    else{
        throw InvalidArguments();
    }
    for (int i = Replacing_begin; i < Replacing_end; i+=2){
        index = CommandHelper::ChangeStringtoInt(command_to_execute[i]);
        nucleotide = CommandHelper::ChangeStringtoChar(command_to_execute[i+1]);
        AnalyzerPtrDst->m_sequence.replace(nucleotide,index);
    }
    CommandHelper::updateMaps(AnalyzerPtrDst,MapOfNames,MapOfIDs,nameOfSequence);
    std::cout << *(MapOfNames[nameOfSequence]) << std::endl;
}

