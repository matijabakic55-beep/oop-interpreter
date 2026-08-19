#include "Time.h"

Time::Time(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

void Time::execute(){
    time_t now = time(nullptr);
    tm* local = localtime(&now);
    result = (local->tm_hour < 10 ? "0" : "") + std::to_string(local->tm_hour) + ":" +
    (local->tm_min  < 10 ? "0" : "") + std::to_string(local->tm_min)  + ":" +
    (local->tm_sec  < 10 ? "0" : "") + std::to_string(local->tm_sec);
    writeText(parsedCmd);
}