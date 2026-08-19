#include "CommandCreator.h"
#include "Time.h"
#include "Date.h"
#include "Echo.h"
#include "Reader.h"
#include "Prompt.h"
#include "Touch.h"
#include "Truncate.h"
#include "Rm.h"
#include "Wc.h"
#include "Head.h"
#include "Tr.h"
#include "Batch.h"
#include "Exec.h"

CommandCreator::CommandCreator(Reader* reader)
    : reader(reader) {}

Command* CommandCreator::createCommand(const ParsedCommand& parsedCommand) {
    if (parsedCommand.name == "echo") return new Echo(parsedCommand, reader);
    if (parsedCommand.name == "prompt") return new Prompt(parsedCommand, reader);
    if (parsedCommand.name == "date") return new Date(parsedCommand, reader);
    if (parsedCommand.name == "time") return new Time(parsedCommand, reader);
    if (parsedCommand.name == "touch") return new Touch(parsedCommand, reader);
    if (parsedCommand.name == "truncate") return new Truncate(parsedCommand, reader);
    if (parsedCommand.name == "rm") return new Rm(parsedCommand, reader);
    if (parsedCommand.name == "wc") return new Wc(parsedCommand, reader);
    if (parsedCommand.name == "head") return new Head(parsedCommand, reader);
    if (parsedCommand.name == "tr") return new Tr(parsedCommand, reader);
    if (parsedCommand.name == "batch") return new Batch(parsedCommand, reader);
    if (parsedCommand.name == "exec") return new Exec(parsedCommand, reader);
    return nullptr;
}