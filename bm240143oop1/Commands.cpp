#include "Commands.h"
#include "Reader.h"

#include <iostream>
#include <fstream>
Command::Command() {}

Command::~Command() {}

string Command::getResult() {
    return result;
}

void Command::setOutput(bool value) {
    output = value;
}

void Command::readFile(const string& filename, string& text) {
    ifstream file(filename);
    if (!file) {
        cout << "Can't open file." << endl;
        return;
    }
    char character;
    while (file.get(character)) text.push_back(character);
}

void Command::readFromConsole(Reader *reader, string& text) {
    string line;
    while (true) {
        line = reader -> getLine();
        if (reader -> isEOF()) break;
        text += line + "\n";
    }
}

void Command::writeTextOverwrite(const string& filename, const string& text) {
    ofstream out(filename);
    if (!out) {
        cout << "Can't open file" << endl;
        return;
    }
    out << text;
}

void Command::writeTextAppend(const string& filename, const string& text) {
    ofstream out(filename, ios::app);
    if (!out) {
        cout << "Can't open file" << endl;
        return;
    }
    out << text;
}

void Command::getText(const ParsedCommand& parsedCmd, Reader* reader, string& text) {
    if (parsedCmd.hasFileArgument){
        string file = parsedCmd.fileArgument;
        readFile(file, text);
    }
    // if there is pipe
    else if (parsedCmd.hasPipedInput) text = parsedCmd.pipedInput;
    // if there is "redirected" input file
    else if (parsedCmd.hasInputRedirect) {
        string file = parsedCmd.inputFile;
        readFile(file, text);
    }
    // if there are multiple lines to be read (there are no arguments)
    else readFromConsole(reader, text);
}

void Command::writeText(const ParsedCommand& parsedCmd) {
    if (!output) return;
    if (parsedCmd.outputMode == OutputMode::Console) {
        if (result != "" && result[result.size() - 1] != '\n') cout << result << endl;
        else cout << result;
    }
    else if (parsedCmd.outputMode == OutputMode::Overwrite) {
        string file = parsedCmd.outputFile;
        writeTextOverwrite(file, result);
    }
    else if (parsedCmd.outputMode == OutputMode::Append) {
        string file = parsedCmd.outputFile;
        writeTextAppend(file, result);
    }
}