#include "Tr.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

Tr::Tr(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

void Tr::execute() {
    string text, what, with;
    bool foundText;
    separate(text, what, with, foundText);
    if (!foundText) getText(parsedCmd, reader, text);
    replace(text, what, with);
    result = text;
    writeText(parsedCmd);
}

void Tr::replace(string &text, const string &what, const string &with) {
    size_t pos = 0;
    while ((pos = text.find(what, pos)) != string::npos) {
        text.replace(pos, what.size(), with);
        pos += with.size();
    }
}

void Tr::separate(string &text, string &what, string &with, bool &foundText) {
    foundText = false;
    vector<string> arguments = parsedCmd.args;
    if (arguments[0][0] == '-' && arguments[0].size() > 1 && arguments[0][1] == '"') {
        what = arguments[0].substr(2, arguments[0].size() - 3);
        if (arguments.size() > 1) with = arguments[1];
    }
    else {
        text = arguments[0];
        foundText = true;
        what = arguments[1].substr(2, arguments[1].size() - 3);
        if (arguments.size() > 2) with = arguments[2];
    }
}