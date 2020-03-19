//
// Created by abuzaid268 on 3/17/20.
//

#include "../command.h"

void del_cmd::execute(vector<string> command_to_execute){
    if (command_to_execute.size() == 2){

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
        /* get the sequence the user wants to delete*/
        AnalyzerPtrSrc = CommandHelper::getProperElement(MapOfNames,MapOfIDs,ID_int,command_to_execute[1]);
        std::cout << "Do you really want to delete " << *AnalyzerPtrSrc << std::endl;
        std::cout << "Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'.\n";
        /*getRespone();*/
        /*string name = command_to_execute[1];*/
        /*string choice;
        back:
        std::cout << "> confirm >>> ";
        std::cin >> choice;
        CommandHelper::toUpper(choice);*/
        if (getRespone()){
            std::cout << "Deleted: " << *AnalyzerPtrSrc << std::endl;
            CommandHelper::deleteSeq(MapOfNames,MapOfIDs,ID_int,command_to_execute[1]);
        }
    }
    else{
        throw InvalidArguments();
    }
}

bool del_cmd::getRespone() {
    string choice;
    back:
    std::cout << "> confirm >>> ";
    std::cin >> choice;
    CommandHelper::toUpper(choice);
    if (choice == "Y" || choice == "N"){
        std::cin.ignore();
        return choice == "Y";
    }
    else{
        std::cout << "You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.\n";
        goto back;
    }
}
