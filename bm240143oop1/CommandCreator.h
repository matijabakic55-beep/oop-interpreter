#pragma once
#include "Parser.h"
#include "Commands.h"
#include "Reader.h"

class CommandCreator {
public:
    CommandCreator(Reader* reader);
    Command* createCommand(const ParsedCommand& parsedCommand);
private:
    Reader* reader;
};