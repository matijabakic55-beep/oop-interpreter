#include "Exec.h"

Exec::Exec(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

/* intuitvno, moze i preko find
void Exec::execute() {
    string text;
    vector<string> arguments = parsedCmd.args;
    if (!arguments.empty()) text = arguments[0];
    int a, b;
    string a1, b1;
    bool first = false;
    char op;
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        if (c == '+' || c == '-' || c == '*' || c == '/')  {
            op = c;
        }
        else if (!isspace(c) && !first) {
            while (!isspace(c) && c != '+' && c != '-' && c != '*' && c != '/') {
                a1.push_back(c);
                c = text[++i];
                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    op = c;
                }
            }
            first = true;
        }
        else if (!isspace(c) && first) {
            while (!isspace(c)) {
                b1.push_back(c);
                c = text[++i];
            }
        }
    }
    a = stoi(a1);
    b = stoi(b1);
    int execution;
    if (op == '+') execution = a + b;
    if (op == '-') execution = a - b;
    if (op == '*') execution = a * b;
    if (op == '/') execution = a / b;
    result = to_string(execution);
    writeText(parsedCmd);
}
*/

void Exec::execute() {
    string text;
    vector<string> arguments = parsedCmd.args;
    if (!arguments.empty()) text = arguments[0];
    int execution;
    string sentence;
    for (char c : text) {
        if (!isspace(c)) sentence.push_back(c);
    }
    int pos = 0;
    string a, b;
    char op;
    for (char c : sentence) {
        if (c != '+' && c != '-' && c != '*' && c != '/') {
            a.push_back(c);
            pos++;
        }
        else {
            op = c;
            break;
        }
    }
    for (int i = pos + 1; i < sentence.size(); i++) b.push_back(sentence[i]);
    int x = stoi(a);
    int y = stoi(b);
    if (op == '+') execution = x + y;
    if (op == '-') execution = x - y;
    if (op == '*') execution = x * y;
    if (op == '/') execution = x / y;
    result = to_string(execution);
    writeText(parsedCmd);
}