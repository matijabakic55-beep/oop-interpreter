#include "Rm.h"

Rm::Rm(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

void Rm::execute() {
    string filename = parsedCmd.fileArgument;
    if (remove(filename.c_str()) != 0) cout << "Can't remove file" << endl;
}