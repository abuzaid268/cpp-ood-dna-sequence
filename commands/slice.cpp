//
// Created by abuzaid268 on 3/16/20.
//
#include "../command.h"
void slice_cmd::execute(vector<string> command_to_execute) {
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

    int begin_int = CommandHelper::ChangeStringtoInt(command_to_execute[2]);
    int end_int = CommandHelper::ChangeStringtoInt(command_to_execute[3]);

    if (command_to_execute.size() == 4) {
        *AnalyzerPtrSrc = AnalyzerPtrSrc->getSlicedString(begin_int,end_int);
        std::cout << *(MapOfNames[AnalyzerPtrSrc->getMSequenceName()]) << std::endl;
    }
    else if (command_to_execute.size() == 6) {
        if (command_to_execute[5] == "@@"){
            nameOfSequence = AnalyzerPtrSrc->getMSequenceName();
            nameOfSequence = CommandHelper::CheckIfNameExists(nameOfSequence,MapOfNames,Sliced);
        }
        else {
            nameOfSequence = CommandHelper::stripName(command_to_execute[5]);
            nameOfSequence = CommandHelper::CheckIfNameExists(nameOfSequence,MapOfNames,Original);
        }
        AnalyzerPtrDst = new DNAAnalyzer(AnalyzerPtrSrc->getSlicedString(begin_int,end_int),++id,nameOfSequence);
        CommandHelper::updateMaps(AnalyzerPtrDst,MapOfNames,MapOfIDs,nameOfSequence);
        std::cout << *(MapOfNames[nameOfSequence]) << std::endl;
    }
    else throw InvalidArguments();
}