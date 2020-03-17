//
// Created by abuzaid268 on 3/17/20.
//
#include "../command.h"

void rename_cmd::execute(vector<string> command_to_execute){
    if (command_to_execute.size() == 3){
        DNAAnalyzer *AnalyzerPtrSrc1;
        DNAContainer *container = DNAContainer::getInstance();

        map<string, DNAAnalyzer *> &MapOfNames = container->getMapOfNames();
        map<int, DNAAnalyzer *> &MapOfIDs = container->getMapOfIDs();

        string nameOfSequence;
        string input_id = CommandHelper::getStripedID(command_to_execute[1]);
        int ID_int = CommandHelper::ChangeStringtoInt(input_id);

        AnalyzerPtrSrc1 = (CommandHelper::getProperElement(MapOfNames, MapOfIDs, ID_int, command_to_execute[1]));
        string old_name = AnalyzerPtrSrc1->getMSequenceName();
        string new_name = CommandHelper::stripName(command_to_execute[2]);

        if (CommandHelper::changeSeqName(new_name, old_name, MapOfNames))
            std::cout << "Changed " << old_name << " to " << new_name << std::endl;
        else
            std::cout << new_name << " is already a name of a sequence, please choose another one" << std::endl;
    }
    else{
        throw InvalidArguments();
    }
}