#pragma once

#include <iostream>
using namespace std;

class Reader {
public:
    Reader(istream* input);
    virtual ~Reader();
    bool getChar(char& c);
    string getLine();
    bool isEOF();
protected:
    istream* input;
};

class ConsoleReader : public Reader {
public:
    ConsoleReader();
};

class FileReader : public Reader {
public:
    FileReader(string path);
    ~FileReader();
};