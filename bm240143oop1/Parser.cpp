#include "Parser.h"
#include "Reader.h"
#include <string>

using namespace std;

// dividing tokens by ", |, <, >, >>, \t
vector<string> Parser::tokenize(const string &line) {
    vector<string> tokens;
    string current;
    bool inQuotes = false;
    for (int index = 0; index < line.size(); index++){
        char sign = line[index];
        if (sign == '"') {
            inQuotes = !inQuotes;
            current.push_back(sign);
        }
        else if (!inQuotes) {
            if (sign == '|') {
                addCurrentToken(tokens, current);
                tokens.push_back("|");
            }
            else if (sign == '<') {
                addCurrentToken(tokens, current);
                tokens.push_back("<");
            }
            else if (sign == '>') addGreaterSign(line, index, tokens, current);
            else if (isspace(sign)) addCurrentToken(tokens, current);
            else current.push_back(sign);
        }
        else current.push_back(sign);
    }
    addCurrentToken(tokens, current);
    return tokens;
}

// spliting by |
vector<vector<string>> Parser::split(const string &line) {
    vector<string> tokens = tokenize(line);
    vector<vector<string>> instructions;
    vector<string> current;
    for (int index = 0; index < tokens.size(); index++) {
        if (tokens[index] != "|") current.push_back(tokens[index]);
        else {
            instructions.push_back(current);
            current.clear();
        }
    }
    instructions.push_back(current);
    return instructions;
}

//parsing for each command
ParsedCommand Parser::parse(const vector<string>& tokens) {
    ParsedCommand cmd;
    cmd.name = tokens[0];
    for (int index = 1; index < tokens.size(); index++) {
        const string& token = tokens[index];
        if (token == "<") {
            if (index + 1 < tokens.size()) {
                cmd.hasInputRedirect = true;
                cmd.inputFile = tokens[index + 1];
                index++;
            }
        }
        else if (token == ">") {
            if (index + 1 < tokens.size()) {
                cmd.outputMode =  OutputMode::Overwrite;
                cmd.outputFile = tokens[index + 1];
                index++;
            }
        }
        else if (token == ">>") {
            if (index + 1 < tokens.size()) {
                cmd.outputMode = OutputMode::Append;
                cmd.outputFile = tokens[index + 1];
                index++;
            }
        }
        else if (token[0] == '-' && token.size() > 1 && token[1] != '"') cmd.options.push_back(token);
        else if (token[0] == '-' && token.size() > 1 && token[1] == '"') cmd.args.push_back(token);
        else if (token[0] != '"') {
            cmd.fileArgument = tokens[index];
            cmd.hasFileArgument = true;
        }
        else cmd.args.push_back(removeQuotes(tokens[index]));
    }
    return cmd;
}

string Parser::removeQuotes(const string& argument) {
    string token = argument.substr(1, argument.length() - 2);
    return token;
}

vector<ParsedCommand> Parser::parsePipeline(const string& line) {
    vector<vector<string>> instructions = split(line);
    vector<ParsedCommand> result;
    for (int index = 0; index < instructions.size(); index++) {
        ParsedCommand cmd = parse(instructions[index]);
        result.push_back(cmd);
    }
    return result;
}

void Parser::addCurrentToken(vector<string>& tokens, string& current) {
    if (!current.empty()) tokens.push_back(current);
    current.clear();
}

void Parser::addGreaterSign(const string& line, int& index, vector<string>& tokens, string& current) {
    if (index + 1 < line.size() && line[index + 1] == '>') {
        tokens.push_back(">>");
        index++;
    }
    else tokens.push_back(">");
}