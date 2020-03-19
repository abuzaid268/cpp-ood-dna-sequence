//
// Created by abuzaid268 on 2/2/20.
//

#ifndef DNA_SEQUENCE_C___COMMAND_H
#define DNA_SEQUENCE_C___COMMAND_H
#include "CommandHelper.h"

struct command{
    virtual void execute(vector<string>) = 0;
    virtual ~command(){};
};

struct CommandObserver{
    virtual void output(string, command*) = 0;
};

struct new_cmd: public command{
    void execute(vector<string>);
};

struct load_cmd: public command{
    void execute(vector<string>);
};

struct save_cmd: public command{
    void execute(vector<string>);
};

struct dup_cmd: public command{
    void execute(vector<string>);
};

struct slice_cmd: public command{
    void execute(vector<string>);
};

struct replace_cmd: public command{
    void execute(vector<string>);
};

struct concat_cmd: public command{
    void execute(vector<string>);
};

struct pair_cmd: public command{
    void execute(vector<string>);
};

struct len_cmd: public command{
    void execute(vector<string>);
};

struct find_cmd: public command{
    void execute(vector<string>);
};

struct count_cmd: public command{
    void execute(vector<string>);
};

struct findall_cmd: public command{
    void execute(vector<string>);
};

struct rename_cmd: public command{
    void execute(vector<string>);
};

struct del_cmd: public command{
    void execute(vector<string>);
    bool getRespone();
};
#endif //DNA_SEQUENCE_C___COMMAND_H
