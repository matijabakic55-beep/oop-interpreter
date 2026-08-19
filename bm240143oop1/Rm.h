#pragma once

#include "Commands.h"
#include "Parser.h"
#include "Reader.h"


class Rm : public Command {
public:
    Rm(const ParsedCommand& parsedCmd, Reader* reader);
    void execute() override;

private:
    ParsedCommand parsedCmd;
    Reader* reader;
};