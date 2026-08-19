#pragma once

#include <string>
#include <vector>
using namespace std;

enum class OutputMode {
    Console,
    Overwrite,
    Append
};

struct ParsedCommand {
    string name;
    vector<string> args;
    vector<string> options;
    string fileArgument;
    bool hasFileArgument = false;
    bool hasInputRedirect = false;
    string inputFile;
    OutputMode outputMode = OutputMode::Console;
    string outputFile;
    string pipedInput;
    bool hasPipedInput = false;
    bool FirstInPipe = false;
};

class Parser {
public:
    vector<ParsedCommand> parsePipeline(const string& line);
private:
    ParsedCommand parse(const vector<string>& tokens);
    vector<string> tokenize(const string& line);
    vector<vector<string>> split(const string& line);
    string removeQuotes(const string& argument);
    void addCurrentToken(vector<string>& tokens, string &current);
    void addGreaterSign(const string& line, int& index, vector<string>& tokens, string& current);
};