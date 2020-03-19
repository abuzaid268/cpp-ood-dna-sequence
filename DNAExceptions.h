//
// Created by abuzaid268 on 1/18/20.
//

#ifndef DNA_SEQUENCE_C___DNAEXCEPTIONS_H
#define DNA_SEQUENCE_C___DNAEXCEPTIONS_H

#include <exception>
struct InvalidNucelotide : std::exception{
    const char * what () const throw ()
    {
        return "The sequence has an invalid nucleotide";
    }

};
struct InvalidIndex : std::exception{
    const char * what () const throw ()
    {
        return "This index is out of the sequence range";
    }

};
struct InvalidCommand : std::exception{
    const char * what () const throw ()
    {
        return "This command does not exist";
    }

};
struct InvalidFile : std::exception{
    const char * what () const throw ()
    {
        return "This file does not exist";
    }

};
struct InvalidSequenceName : std::exception{
    const char * what () const throw ()
    {
        return "This Sequence does not exist";
    }

};
struct InvalidArguments : std::exception{
    const char * what () const throw ()
    {
        return "Number of Arguments does not match command specifications";
    }
};
struct InvalidInputStyle : std::exception{
    const char * what () const throw ()
    {
        return "the seq name does not include @, or an ID is not correct";
    }

};
struct InvalidFindNucleotides : std::exception{
    const char * what () const throw ()
    {
        return "the given nucleotides to look for are invalid";
    }

};


#endif //DNA_SEQUENCE_C___DNAEXCEPTIONS_H
