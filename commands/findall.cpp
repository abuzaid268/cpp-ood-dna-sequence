//
// Created by abuzaid268 on 3/16/20.
//

#include "../command.h"

void findall_cmd::execute(vector<string> command_to_execute){
    /* this pointer is used to insert the same ptr to two maps*/
    DNAAnalyzer* AnalyzerPtrSrc;
    DNAAnalyzer* AnalyzerPtrSrc2;
    /* gets the singleton instance */
    DNAContainer* container = DNAContainer::getInstance();
    /* get both maps from the container, both will be updated */
    map<string,DNAAnalyzer*> &MapOfNames = container->getMapOfNames();
    map<int, DNAAnalyzer *> &MapOfIDs = container->getMapOfIDs();


    string input_id = CommandHelper::getStripedID(command_to_execute[1]);
    int ID_int = CommandHelper::ChangeStringtoInt(input_id);

    AnalyzerPtrSrc = CommandHelper::getProperElement(MapOfNames,MapOfIDs,ID_int,command_to_execute[1]);

    if (command_to_execute.size() == 3){
        if (command_to_execute[2][0] != '#' && command_to_execute[2][0] != '@') {
            string to_find = command_to_execute[2];
            CommandHelper::toUpper(to_find);
            for (int i = 0; i < to_find.size(); i++) {
                if (CommandHelper::CheckSequenceNotValid(to_find[i])) {
                    throw InvalidFindNucleotides();
                }
            }
            std::vector<int> indices = AnalyzerPtrSrc->m_sequence.findAll(to_find);
            for(int i = 0; i < indices.size(); i++){
                std::cout << indices[i] << " ";
            }
            std::cout << std::endl;
        }
        else{
            string input_id2 = CommandHelper::getStripedID(command_to_execute[2]);
            int ID_int2 = CommandHelper::ChangeStringtoInt(input_id2);

            AnalyzerPtrSrc2 = CommandHelper::getProperElement(MapOfNames,MapOfIDs,ID_int2,command_to_execute[2]);

            string to_find = AnalyzerPtrSrc2->m_sequence.getString();
            std::vector<int> indices = AnalyzerPtrSrc->m_sequence.findAll(to_find);
            for(int i = 0; i < indices.size(); i++){
                std::cout << indices[i] << " ";
            }
            std::cout << std::endl;
        }
    }
    else{
        throw InvalidArguments();
    }
}