#pragma once

#include "Commands.h"
#include "Parser.h"

class Time : public Command {
public:
    Time(const ParsedCommand& parsedCmd, Reader* reader);
    void execute() override;

private:
    ParsedCommand parsedCmd;
    Reader* reader;
};