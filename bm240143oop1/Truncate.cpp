#include "Truncate.h"
#include <fstream>

Truncate::Truncate(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

void Truncate::execute() {
    vector<string> arguments = parsedCmd.args;
    string filename = parsedCmd.fileArgument;
    ifstream in(filename);
    if (!in) {
        cout << "Can't open file" << endl;
        return;
    }
    in.close();
    ofstream out(filename, ios::trunc);
    if (!out) cout << "Can't open file" << endl;
}