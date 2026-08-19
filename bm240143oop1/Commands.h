#pragma once

#include <string>
#include "Reader.h"
#include "Parser.h"

using namespace std;

class Command {
public:
    Command();
    virtual ~Command();
    virtual void execute() = 0;
    string getResult();
    void setOutput(bool value);
protected:
    string result;
    bool output = false;
    void getText(const ParsedCommand& parsedCmd, Reader* reader, string& text);
    void writeText(const ParsedCommand& parsedCmd);
private:
    void readFile(const string& filename, string& text);
    void readFromConsole(Reader* reader, string& text);
    void writeTextOverwrite(const string& filename, const string& text);
    void writeTextAppend(const string& filename, const string& text);
};