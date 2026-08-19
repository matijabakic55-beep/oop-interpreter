#include "Interpreter.h"
#include "Commands.h"
#include "Parser.h"
#include "CommandCreator.h"

#include <iostream>
#include <exception>

using namespace std;

Interpreter* Interpreter::instance = nullptr;

Interpreter::Interpreter(Reader* reader, string prompt)
    : reader(reader), prompt(prompt) {}

Interpreter* Interpreter::getInstance(Reader* reader, string prompt) {
    if (instance == nullptr) instance = new Interpreter(reader, prompt);
    return instance;
}

Interpreter::~Interpreter() {
    delete reader;
}

void Interpreter::run() {
    while (!reader->isEOF()) {
        try {
            cout << prompt << " ";
            string line = reader->getLine();
            executeLine(line);
        }
        catch (exception& e) {
            cout << "Greska: " << e.what() << endl;
        }
    }
}

void Interpreter::executeLine(const string& line, const ParsedCommand* parentCmd) {
    if (line.empty()) return;

    vector<ParsedCommand> instructions = parser.parsePipeline(line);

    if (parentCmd != nullptr && !instructions.empty()) {
        if (instructions.back().outputMode == OutputMode::Console) {
            instructions.back().outputMode = parentCmd->outputMode;
            instructions.back().outputFile = parentCmd->outputFile;
        }
    }

    CommandCreator creator(reader);
    string text = "";

    for (int index = 0; index < instructions.size(); index++) {
        if (index > 0) {
            instructions[index].pipedInput = text;
            instructions[index].hasPipedInput = true;
        }

        Command* cmd = creator.createCommand(instructions[index]);
        if (cmd != nullptr) {
            if (index == instructions.size() - 1) cmd->setOutput(true);
            else cmd->setOutput(false);

            cmd->execute();
            text = cmd->getResult();
            delete cmd;
        }
    }
}

void Interpreter::setPrompt(const string& prompt){
    this -> prompt = prompt;
}