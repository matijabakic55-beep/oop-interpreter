#pragma once

#include "Commands.h"
#include "Parser.h"
#include "Reader.h"


class Prompt : public Command {
public:
    Prompt(const ParsedCommand& parsedCmd, Reader* reader);
    void execute() override;
private:
    ParsedCommand parsedCmd;
    Reader* reader;
};