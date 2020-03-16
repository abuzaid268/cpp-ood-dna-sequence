//
// Created by abuzaid268 on 3/16/20.
//
#include "../command.h"

void len_cmd::execute(vector<string>command_to_execute){
    /* this pointer is used to insert the same ptr to two maps*/
    DNAAnalyzer* AnalyzerPtrSrc;
    /* gets the singleton instance */
    DNAContainer* container = DNAContainer::getInstance();
    /* get both maps from the container, both will be updated */
    map<string,DNAAnalyzer*> &MapOfNames = container->getMapOfNames();
    map<int, DNAAnalyzer *> &MapOfIDs = container->getMapOfIDs();
    std::string nameOfSequence;
    string input_id = CommandHelper::getStripedID(command_to_execute[1]);
    int ID_int = CommandHelper::ChangeStringtoInt(input_id);
    AnalyzerPtrSrc = CommandHelper::getProperElement(MapOfNames,MapOfIDs,ID_int,command_to_execute[1]);
    if (command_to_execute.size() == 2){
        std::cout << AnalyzerPtrSrc->m_sequence.getSequenceLength() << std::endl;
    }
    else{
        throw InvalidArguments();
    }
}