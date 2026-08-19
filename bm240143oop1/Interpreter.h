#pragma once

#include "Reader.h"
#include "Commands.h"
#include "Parser.h"

using namespace std;

class Interpreter {
public:
    //Returns the singleton instance of this class. Static.
    static Interpreter* getInstance(Reader* reader = nullptr, string prompt = "$");
    ~Interpreter();
    void run();
    void setPrompt(const string& prompt);
    void executeLine(const string& line, const ParsedCommand* parentCmd = nullptr);
private:
    Interpreter(Reader* reader, string prompt);
    static Interpreter* instance;
    Reader* reader;
    Parser parser;
    string prompt;
};