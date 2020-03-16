//
// Created by abuzaid268 on 3/16/20.
//
#include "../command.h"

void new_cmd::execute(vector<string> command_to_execute) {
    /*
     creates a new sequence, if the name is given, it will give it that name, if not it will automatically assign a name for it
    */
    /* this pointer is used to insert the same ptr to two maps*/
    DNAAnalyzer* AnalyzerPtr;
    /* gets the singleton instance */
    DNAContainer* container = DNAContainer::getInstance();
    /* used to generate a name if it is not given */
    std::ostringstream stm ;
    /* gets the most recent id from the container */
    int &id = DNAContainer::getID();
    /* get both maps from the container, both will be updated */
    map<string,DNAAnalyzer*> &MapOfNames = container->getMapOfNames();
    map<int, DNAAnalyzer *> &MapOfIDs = container->getMapOfIDs();

    /* checks if the name is given */
    if (command_to_execute.size() == 3){
        /* the format specifies to use @, this functions returns it without it, if not provided, exception is thrown */
        string strippedName = CommandHelper::stripName(command_to_execute[2]);
        /* checks if the name of the sequence already exists, if so it will do _# after the original name */
        std::string nameOfSequence = CommandHelper::CheckIfNameExists(strippedName,MapOfNames,Original);
        /* updates the maps and prints the sequence */
        AnalyzerPtr = new DNAAnalyzer(command_to_execute[1],++id,nameOfSequence);
        CommandHelper::updateMaps(AnalyzerPtr,MapOfNames,MapOfIDs,nameOfSequence);
        std::cout << *(MapOfNames[nameOfSequence]) << std::endl;
    }
    else if (command_to_execute.size() == 2){
        /* used when a name is not provided */
        string defaultname;
        stm << ++id ;
        defaultname += "seq";
        defaultname += stm.str();
        AnalyzerPtr = new DNAAnalyzer(command_to_execute[1],id,defaultname);
        CommandHelper::updateMaps(AnalyzerPtr,MapOfNames,MapOfIDs,defaultname);
        std::cout << *(MapOfNames[defaultname]) << std::endl;
    }
    else{
        throw InvalidArguments();
    }
}