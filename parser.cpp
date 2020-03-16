//
// Created by abuzaid268 on 2/2/20.
//

#include "parser.h"
std::string getSlicedString(int begin, int end, std::string input){
    std::string x;
    for (int i = begin; i < end; i++ ){
        x+= input[i];
    }
    return x;
}
vector<string> Parser::getCommand(string command) {
    vector<string> commands;
    int last_index = 0;
    int stringlength = command.length();
    for (int i = 0; i < stringlength; i++){
        if (command[i] == ' '){
                commands.push_back(getSlicedString(last_index,i,command));
            last_index = i + 1;
        }
        else if (i == stringlength - 1){
                commands.push_back(getSlicedString(last_index,i+1,command));
            last_index = 0;
        }
    }
    return commands;
}
