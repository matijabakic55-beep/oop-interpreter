#pragma once

#include "Commands.h"
#include "Parser.h"
#include "Reader.h"


class Batch : public Command {
public:
    Batch(const ParsedCommand& parsedCmd, Reader* reader);
    void execute() override;

private:
    ParsedCommand parsedCmd;
    Reader* reader;
};