#include "Head.h"
#include <iostream>
#include <iomanip>
#include <fstream>

Head::Head(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

void Head::execute() {
    vector<string> options = parsedCmd.options;
    string option = options[0].substr(2, options[0].size() - 2);
    string text;
    vector<string> arguments = parsedCmd.args;
    if (!arguments.empty()) text = arguments[0];
    else getText(parsedCmd, reader, text);
    removeText(text, option);
    result = text;
    writeText(parsedCmd);
}

void Head::removeText(string& text, string option) {
    int counter = 0;
    int numberLines = stoi(option);
    if (numberLines == 0) {
        text = "";
        return;
    }
    int divider = text.size();
    for (int index = 0; index < text.size() && counter < numberLines; index++) {
        if (text[index] == '\n') {
            counter++;
            divider = index + 1;
        }
    }
    text = text.substr(0, divider);
}