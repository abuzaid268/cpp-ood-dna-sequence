#include <iostream>
#include "parser.h"
#include "factory.h"
#include "command.h"
#include "DNAExceptions.h"
#include <memory>
using namespace std;

int main() {
    std::string input;
    vector<string> inputs;
    command *cmd = NULL;
    while (input != "quit") {
        cout << "> cmd >>> ";
        getline(cin, input);
        if (input != "quit") {
            inputs = Parser::getCommand(input);
            try {
                cmd = (factory::method(inputs));
                cmd->execute(inputs);
                inputs.clear();
            }
            catch (exception &e) {
                cout << e.what() << endl;
            }
        }
    }
    factory::delete_ptrs();
}