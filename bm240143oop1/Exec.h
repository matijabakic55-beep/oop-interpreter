#pragma once

#include "Commands.h"
#include "Parser.h"
#include "Reader.h"


class Exec : public Command {
public:
    Exec(const ParsedCommand& parsedCmd, Reader* reader);
    void execute() override;

private:
    ParsedCommand parsedCmd;
    Reader* reader;
};