//
// Created by abuzaid268 on 3/16/20.
//
#include "../command.h"

void load_cmd::execute(vector<string> command_to_execute) {
    DNAAnalyzer* AnalyzerPtr;
    DNAContainer *container = DNAContainer::getInstance();
    map<string, DNAAnalyzer *> &MapOfNames = container->getMapOfNames();
    map<int, DNAAnalyzer *> &MapOfIDs = container->getMapOfIDs();
    int &id = DNAContainer::getID();
    string contained_string = file_processing::readFile(command_to_execute[1].c_str());
    string defaultname;
    if (command_to_execute.size() == 3) {
        string strippedName = CommandHelper::stripName(command_to_execute[2]);
        std::string nameOfSequence =  CommandHelper::CheckIfNameExists(strippedName,MapOfNames,Original);
        AnalyzerPtr = new DNAAnalyzer(contained_string,++id,nameOfSequence);
        CommandHelper::updateMaps(AnalyzerPtr,MapOfNames,MapOfIDs,nameOfSequence);
        std::cout << *(MapOfNames[nameOfSequence]) << std::endl;
    }
    else if (command_to_execute.size() == 2){
        for (int i = 0; i < command_to_execute[1].length();i++){
            if (command_to_execute[1][i] != '.')
                defaultname += command_to_execute[1][i];
            else
                break;
        }
        std::string nameOfSequence = CommandHelper::CheckIfNameExists(defaultname,MapOfNames,Original);
        AnalyzerPtr = new DNAAnalyzer(contained_string,++id,nameOfSequence);
        CommandHelper::updateMaps(AnalyzerPtr,MapOfNames,MapOfIDs,nameOfSequence);
        std::cout << *(MapOfNames[nameOfSequence]) << std::endl;
    }
    else{
        throw InvalidArguments();
    }
}