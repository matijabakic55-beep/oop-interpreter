#include "Prompt.h"
#include "Interpreter.h"

using namespace std;

Prompt::Prompt(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

void Prompt::execute() {
    Interpreter* interpreter = Interpreter::getInstance();
    vector<string> arguments = parsedCmd.args;
    string prompt = arguments[0];
    interpreter -> setPrompt(prompt);
}