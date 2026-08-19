#include "Echo.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Echo::Echo(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

void Echo::execute() {
    string text;
    vector<string> arguments = parsedCmd.args;
    if (!arguments.empty()) text = arguments[0];
    else getText(parsedCmd, reader, text);
    result = text;
    writeText(parsedCmd);
}