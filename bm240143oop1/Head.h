#pragma once

#include "Commands.h"
#include "Parser.h"
#include "Reader.h"


class Head : public Command {
public:
    Head(const ParsedCommand& parsedCmd, Reader* reader);
    void execute() override;

private:
    ParsedCommand parsedCmd;
    Reader* reader;
    void removeText(string& text, string option);
};