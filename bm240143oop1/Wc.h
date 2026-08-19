#pragma once

#include "Commands.h"
#include "Parser.h"
#include "Reader.h"


class Wc : public Command {
public:
    Wc(const ParsedCommand& parsedCmd, Reader* reader);
    void execute() override;
private:
    ParsedCommand parsedCmd;
    Reader* reader;
    int countWords(const string& text);
    int countCharacters(const string& text);
};