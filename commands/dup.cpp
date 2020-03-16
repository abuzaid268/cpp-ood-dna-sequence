//
// Created by abuzaid268 on 3/16/20.
//
#include "../command.h"

void dup_cmd::execute(vector<string> command_to_execute) {
    DNAAnalyzer* AnalyzerPtr;
    DNAAnalyzer* AnalyzerPtrSrc;
    DNAContainer* container = DNAContainer::getInstance();
    map<string,DNAAnalyzer*> &MapOfNames = container->getMapOfNames();
    map<int, DNAAnalyzer *> &MapOfIDs = container->getMapOfIDs();
    int &id = DNAContainer::getID();
    std::string nameOfSequence;
    string input_id = CommandHelper::getStripedID(command_to_execute[1]);
    int ID_int = CommandHelper::ChangeStringtoInt(input_id);
    AnalyzerPtrSrc = CommandHelper::getProperElement(MapOfNames,MapOfIDs,ID_int,command_to_execute[1]);
    if (command_to_execute.size() == 4){
        if (command_to_execute[3] == "@@")
            nameOfSequence = AnalyzerPtrSrc->getMSequenceName();
        else
            nameOfSequence = CommandHelper::stripName(command_to_execute[3]);
        nameOfSequence = CommandHelper::CheckIfNameExists(nameOfSequence, MapOfNames,Original);
        AnalyzerPtr = new DNAAnalyzer(AnalyzerPtrSrc->m_sequence.getString(), ++id, nameOfSequence);
        CommandHelper::updateMaps(AnalyzerPtr,MapOfNames,MapOfIDs,nameOfSequence);
        std::cout << *(MapOfNames[nameOfSequence]) << std::endl;
    }
    else if (command_to_execute.size() == 2) {
        nameOfSequence = CommandHelper::CheckIfNameExists(AnalyzerPtrSrc->getMSequenceName(),MapOfNames,Original);
        AnalyzerPtr = new DNAAnalyzer(AnalyzerPtrSrc->m_sequence.getString(),++id,nameOfSequence);
        CommandHelper::updateMaps(AnalyzerPtr,MapOfNames,MapOfIDs,nameOfSequence);
        std::cout << *(MapOfNames[nameOfSequence]) << std::endl;
    }
    else{
        throw InvalidArguments();
    }
}