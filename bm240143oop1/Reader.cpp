#include "Reader.h"

#include <fstream>
using namespace std;

Reader::Reader(istream* input)
    : input(input){}

Reader::~Reader() {}

string Reader::getLine() {
    string line;
    getline(*input, line);
    return line;
}

bool Reader::getChar(char& c) {
    if (input->get(c)) return true;
    return false;
}

bool Reader::isEOF() {
    if (input -> eof()) {
        input -> clear();
        return true;
    }
    return false;
}

ConsoleReader::ConsoleReader()
    : Reader(&cin) {}

FileReader::FileReader(string path)
    : Reader(new ifstream(path)) {}

FileReader::~FileReader() {
    delete input;
}