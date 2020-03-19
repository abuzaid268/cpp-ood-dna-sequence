//
// Created by abuzaid268 on 3/16/20.
//
#include "../command.h"
void save_cmd::execute(vector<string> command_to_execute) {
    DNAContainer *container = DNAContainer::getInstance();
    map<string, DNAAnalyzer *> &MapOfNames = container->getMapOfNames();

    if (MapOfNames[CommandHelper::stripName(command_to_execute[1])]){
        if (command_to_execute.size() == 3) {
            file_processing::writeFile(command_to_execute[2].c_str(), MapOfNames[command_to_execute[1]]->getString());
        }
        else if (command_to_execute.size() == 2){
            string filename = MapOfNames[CommandHelper::stripName(command_to_execute[1])]->getMSequenceName();
            filename += ".rawdna";
            file_processing::writeFile(filename.c_str(), MapOfNames[command_to_execute[1]]->getString());
        }
        else{
            throw InvalidArguments();
        }
    }
    else
        std::cout << "invalid sequence name" << std::endl;

}