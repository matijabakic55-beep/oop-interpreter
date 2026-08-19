#pragma once

#include "Commands.h"
#include "Parser.h"
#include "Reader.h"


class Echo : public Command {
public:
    Echo(const ParsedCommand& parsedCmd, Reader* reader);
    void execute() override;

private:
    ParsedCommand parsedCmd;
    Reader* reader;
};