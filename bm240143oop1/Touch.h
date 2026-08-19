#pragma once

#include "Commands.h"
#include "Parser.h"
#include "Reader.h"

class Touch : public Command {
public:
    Touch(const ParsedCommand& parsedCmd, Reader* reader);
    void execute() override;
private:
    ParsedCommand parsedCmd;
    Reader* reader;
};