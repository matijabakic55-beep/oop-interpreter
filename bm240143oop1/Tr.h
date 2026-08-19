#pragma once

#include "Commands.h"
#include "Parser.h"
#include "Reader.h"


class Tr : public Command {
public:
    Tr(const ParsedCommand& parsedCmd, Reader* reader);
    void execute() override;
private:
    ParsedCommand parsedCmd;
    Reader* reader;
    void replace(string& text, const string& what, const string& with);
    void separate(string& text, string& what, string& with, bool& foundText);
};