#include "Wc.h"
#include <fstream>

Wc::Wc(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

void Wc::execute() {
    vector<string> options = parsedCmd.options;
    string option = options[0];
    string text;
    vector<string> arguments = parsedCmd.args;
    if (!arguments.empty()) text = arguments[0];
    else getText(parsedCmd, reader, text);
    if (option == "-c") result = to_string(countCharacters(text));
    else if (option == "-w") result = to_string(countWords(text));
    writeText(parsedCmd);
}

int Wc::countCharacters(const string& text) {
    return text.size();
}

int Wc::countWords(const string& text) {
    bool inWord = false;
    int counter = 0;
    for (char sign : text) {
        if (isspace(sign)) inWord = false;
        else if (inWord == false) {
            inWord = true;
            counter++;
        }
    }
    return counter;
}