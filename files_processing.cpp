//
// Created by abuzaid268 on 2/1/20.
//

#include <iostream>
#include "files_processing.h"
#include <unistd.h>
#include "DNAExceptions.h"

std::string file_processing::readFile(const char * filename) {
    std::string line;
    std::string sequences;
    std::ifstream DnaFile;
    DnaFile.open(filename);
    if (DnaFile.is_open())
    {
        while ( getline (DnaFile,line) )
        {
            sequences.append(line);
        }
        DnaFile.close();
    }
    else{
        /*std::cout << "The file Does not exist" << std::endl;*/
        throw InvalidFile();
    }
    return sequences;
}

void file_processing::writeFile(const char * filename, std::string output) {
    std::ofstream DnaFile;
    std::string path = get_current_dir_name();
    path += '/';
    path += filename;
    DnaFile.open(path.c_str());
    if (DnaFile.is_open())
    {   DnaFile << output;
        std::cout << "Successfully written to " << path << std::endl;
    }
    else{
        std::cout << "Failed to write to " << filename << std::endl;
    }
}
