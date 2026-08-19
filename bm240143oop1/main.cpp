#include "Interpreter.h"

int main() {
    Interpreter* interpreter = Interpreter::getInstance(new ConsoleReader());
    interpreter->run();
    return 0;
}