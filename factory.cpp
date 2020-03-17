//
// Created by abuzaid268 on 2/2/20.
//

#include "factory.h"
#include "DNAExceptions.h"
using std::string;
static map<string,command*> initMap(){
    map<string,command* > Commands;
    Commands["new"] = new new_cmd();
    Commands["load"] = new load_cmd();
    Commands["save"] = new save_cmd();
    Commands["dup"] = new dup_cmd();
    Commands["slice"] = new slice_cmd();
    Commands["replace"] = new replace_cmd();
    Commands["concat"] = new concat_cmd();
    Commands["pair"] = new pair_cmd();
    Commands["len"] = new len_cmd();
    Commands["find"] = new find_cmd();
    Commands["count"] = new count_cmd();
    Commands["findall"] = new findall_cmd();
    Commands["rename"] = new rename_cmd();
    return Commands;

}
map<string,command*> Commands = initMap();
command *factory::method(vector<string>& command_string){
    if (Commands[command_string[0]])
        return Commands[command_string[0]];
    else
        throw InvalidCommand();
}

void factory::delete_ptrs() {
    delete Commands["new"];
    delete Commands["load"];
    delete Commands["save"];
    delete Commands["dup"];
    delete Commands["slice"];
    delete Commands["replace"];
    delete Commands["concat"];
    delete Commands["pair"];
    delete Commands["len"];
    delete Commands["find"];
    delete Commands["count"];
    delete Commands["findall"];
    delete Commands["rename"];

}
