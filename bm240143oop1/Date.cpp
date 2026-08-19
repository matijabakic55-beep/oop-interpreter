#include "Date.h"

Date::Date(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

void Date::execute() {
    time_t now = time(nullptr);
    tm* local = localtime(&now);
    result = (local->tm_mday < 10 ? "0" : "") + to_string(local->tm_mday) + "." +
    (local->tm_mon + 1 < 10 ? "0" : "") + to_string(local->tm_mon + 1) + "." +
    to_string(local->tm_year + 1900);
    writeText(parsedCmd);
}