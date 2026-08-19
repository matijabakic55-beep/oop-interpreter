#include "Batch.h"
#include "Interpreter.h"

#include <iostream>
#include <fstream>

using namespace std;

Batch::Batch(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

void Batch::execute() {
    vector<string> arguments = parsedCmd.args;
    string line;
    ifstream file(parsedCmd.fileArgument);
    if (!file) {
        cout << "Can't open file." << endl;
        return;
    }
    while (getline(file, line)) {
        if (line.empty()) continue;
        try {
            Interpreter::getInstance()->executeLine(line, &parsedCmd);
        }
        catch (exception& e) {
            cerr << "Greska: " << e.what() << endl;
        }
    }
}