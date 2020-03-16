//
// Created by abuzaid268 on 3/16/20.
//
#include "../command.h"


void concat_cmd::execute(vector<string> command_to_execute) {
    /* > cmd >>> concat <seq_1> <seq_2> [: [@<new_seq_name>|@@]] */
    /* concatenates <seq_2> at the end of seq_1. */

    /* pointers to the */
    DNAAnalyzer* AnalyzerPtrDst;
    DNAAnalyzer* AnalyzerPtrSrc1;
    DNAContainer* container = DNAContainer::getInstance();
    map<string,DNAAnalyzer*> &MapOfNames = container->getMapOfNames();
    map<int, DNAAnalyzer *> &MapOfIDs = container->getMapOfIDs();
    string nameOfSequence;
    string input_id;
    int &id = DNAContainer::getID();
    int ID_int;
    int command_size = command_to_execute.size();
    DNAAnalyzer temp;
    temp.m_sequence = "";
    if (command_to_execute[command_size - 2 ] == ":"){
        for (int i = 1; i < command_size - 2; i++){
            input_id = CommandHelper::getStripedID(command_to_execute[i]);
            ID_int = CommandHelper::ChangeStringtoInt(input_id);
            AnalyzerPtrSrc1 = (CommandHelper::getProperElement(MapOfNames,MapOfIDs,ID_int,command_to_execute[i]));
            temp.m_sequence =  temp.m_sequence + AnalyzerPtrSrc1->m_sequence ;
            nameOfSequence += AnalyzerPtrSrc1->getMSequenceName();
            /*nameOfSequence = CommandHelper::CheckIfNameExists(nameOfSequence,MapOfNames,Concatenated);*/
        }
        if (command_size - 1 == 2)
            nameOfSequence = CommandHelper::CheckIfNameExists(nameOfSequence,MapOfNames,Concatenated);
        else{
            nameOfSequence = "conseq";
            nameOfSequence = CommandHelper::CheckIfNameExists(nameOfSequence,MapOfNames,Original);
        }
        if (command_to_execute[command_size - 1] == "@@"){
            input_id = CommandHelper::getStripedID(command_to_execute[1]);
            ID_int = CommandHelper::ChangeStringtoInt(input_id);
            AnalyzerPtrSrc1 = (CommandHelper::getProperElement(MapOfNames,MapOfIDs,ID_int,command_to_execute[1]));
        }
        else {
            nameOfSequence = CommandHelper::stripName(command_to_execute[command_size - 1]);
            nameOfSequence = CommandHelper::CheckIfNameExists(nameOfSequence,MapOfNames,Original);
        }
        AnalyzerPtrDst = new DNAAnalyzer(temp.m_sequence,++id,nameOfSequence);
        CommandHelper::updateMaps(AnalyzerPtrDst,MapOfNames,MapOfIDs,nameOfSequence);
        std::cout << *(MapOfNames[nameOfSequence]) << std::endl;
    }
    else if (command_to_execute[command_size - 2 ] != ":"){
        for (int i = 1; i < command_size; i++){
            input_id = CommandHelper::getStripedID(command_to_execute[i]);
            ID_int = CommandHelper::ChangeStringtoInt(input_id);
            AnalyzerPtrSrc1 = (CommandHelper::getProperElement(MapOfNames,MapOfIDs,ID_int,command_to_execute[i]));
            temp.m_sequence =  temp.m_sequence + AnalyzerPtrSrc1->m_sequence ;
        }
        input_id = CommandHelper::getStripedID(command_to_execute[1]);
        ID_int = CommandHelper::ChangeStringtoInt(input_id);
        AnalyzerPtrSrc1 = (CommandHelper::getProperElement(MapOfNames,MapOfIDs,ID_int,command_to_execute[1]));
        AnalyzerPtrSrc1->m_sequence = temp.m_sequence;
        nameOfSequence = AnalyzerPtrSrc1->getMSequenceName();
        std::cout << *(MapOfNames[nameOfSequence]) << std::endl;
    }
    else throw InvalidArguments();

}