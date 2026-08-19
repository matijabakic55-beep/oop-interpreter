#include "Touch.h"
#include <fstream>

Touch::Touch(const ParsedCommand& parsedCmd, Reader* reader)
    : parsedCmd(parsedCmd), reader(reader) {}

void Touch::execute() {
    string filename = parsedCmd.fileArgument;
    ifstream in(filename);
    if (in) {
        cout << "File already exists." << endl;
        return;
    }
    ofstream out(filename);
    if (!out) cout << "Can't create file." << endl;
}