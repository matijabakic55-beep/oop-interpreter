#pragma once

#include "Commands.h"
#include "Parser.h"

class Date : public Command {
public:
    Date(const ParsedCommand& parsedCmd, Reader* reader);
    void execute() override;
private:
    ParsedCommand parsedCmd;
    Reader* reader;
};